#!/usr/bin/env python3
#
# Testing tool for Murder problem
#
# Utilisation:
#
#   python3 testing_tool.py -f inputfile <programme>
#
#
# Utilisez -f pour spécifier le fichier d'entrée par exemple. 1.in.
# Format d'un fichier d'entrée:
#   - Le nombre de personnes dans le manoir
#   - Le noms des personnes dans le manoir
#   - Le meurtirer
#   - Le nombre liens dans le graphe
#   - Lignes disant si A à vu B
#
# Vous pouvez compiler et lancer votre solution comme ceci:

# C++:
#   g++ solution.cpp
#   python3 testing_tool.py -f 1.in ./a.out

# Python3
#   python3 testing_tool.py -f 1.in python3 ./solution.py

# Java
#   javac solution.java
#   python3 testing_tool.py -f 1.in java solution

# Kotlin
#   kotlinc solution.kt
#   python3 testing_tool.py -f 1.in kotlin solutionKt


# The tool is provided as-is, and you should feel free to make
# whatever alterations or augmentations you like to it.
#
# The tool attempts to detect and report common errors, but it is not an exhaustive test.
# It is not guaranteed that a program that passes this testing tool will be accepted.


import argparse
import subprocess
import traceback


def write(p, line):
    assert p.poll() is None, "Program terminated early"
    print(f"Write: {line}", flush=True)
    p.stdin.write(f"{line}\n")
    p.stdin.flush()


def read(p):
    assert p.poll() is None, "Program terminated early"
    line = p.stdout.readline().strip()
    assert line != "", "Read empty line or closed output pipe"
    print(f"Read: {line}", flush=True)
    return line


parser = argparse.ArgumentParser(description="Testing tool for problem King of the Hill.")
parser.add_argument(
    "-f",
    dest="inputfile",
    metavar="inputfile",
    default=None,
    type=argparse.FileType("r"),
    required=True,
    help="The input file to use.",
)
parser.add_argument("program", nargs="+", help="Invocation of your solution")

args = parser.parse_args()

with args.inputfile as f:
    lines = f.readlines()
    assert len(lines) > 0
    n = int(lines[0].strip())
    
    max_queries = n-1

    peoples = [lines.strip() for lines in lines[1:n+1]]
    murderer = lines[n+1].strip()

    seen = {}
    for i in peoples:
        seen[i] = {}

    for i in peoples:
        for j in peoples:
            seen[i][j] = "NON"
    m = int(lines[n+2].strip())

    for i in range(m):
        a, b = lines[n+3+i].strip().split(" ")
        seen[a][b] = "OUI"

with subprocess.Popen(
    " ".join(args.program),
    shell=True,
    stdout=subprocess.PIPE,
    stdin=subprocess.PIPE,
    universal_newlines=True,
) as p:
    try:
        write(p, n)

        for people in peoples:
            write(p, people)

        queries = 0
        while True:
            op, *rest = read(p).split()
            if op == "?":
                queries += 1
                a, b = map(str, rest)

                # TODO check not in people
                write(p, seen[a][b])

            elif op == "!":
                v = str(rest[0])
                assert v == murderer, f"You printed {v}, but the answer is {murderer}."
                break
            else:
                assert False, f"Operation '{op}' is not one of '?' or '!'."

        assert (
            p.stdout.readline() == ""
        ), "Your submission printed extra data after finding a solution."
        assert p.wait() == 0, "Your submission did not exit cleanly after finishing."

        assert (
            queries <= max_queries
        ), f"Used {queries} queries, which is more than the allowed 10n+100 ({max_queries})."

        print(f"\nSuccess.\nQueries used: {queries}\n")

    except AssertionError as e:
        print()
        print(f"Error: {e}")
        print()
        try:
            p.wait(timeout=2)
        except subprocess.TimeoutExpired:
            print("Killing your submission after 2 second timeout.")
            p.kill()

    except Exception as e:
        print()
        traceback.print_exc()
        print()
        try:
            p.wait(timeout=2)
        except subprocess.TimeoutExpired:
            print("Killing your submission after 2 second timeout.")
            p.kill()
        raise e

    finally:
        print(f"Exit code: {p.wait()}\n", flush=True)
