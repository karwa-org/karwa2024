# KARWa 2024: Problemset

Problemset for the first edition of KARWa.

This uses [Ragnar's awesome BAPCtools scripts](https://github.com/RagnarGrootKoerkamp/BAPCtools).

## Building problemset

Assuming you already have BAPCtools installed, simply run:

```console
bt pdf
```

This will create a `contest.<lang>.pdf` document, with the full problemset.

If you don't want to figure out what LaTeX's cryptic error messages mean, you can install the `texlive-full` metapackage on most Linux distros.
This should fix most problems you may have!


To get the beamer `solutions.<lang>.pdf` for solutions, run:

```console
bt solutions
```


## Testing

To make sure all the sample & secret testcases work correctly, run:

```console
bt run
```

## Problem expected difficulty (from bottom to top)
### Hard
- Bombe
- 24H vélo
- Espion
- Hubs

### Medium
- Flot
- SNCB
- Ping-pong
- Pairmutation

### Easy
- Meurtrier
- Antennes
- Rollercoaster
- Tomates


## Useful Commands

Compress the contest into one zip file and compile web contest and solutions PDF:

```console
bt zip
```

## During Contest

Download [ICPC Tools Resolver and Client-Presentation](https://tools.icpc.global/) (v2.5.984) and run them while a contest is active to get some animation.

While the contest is running, get cool presentations on screens, e.g. to get scoreboard and clock, run:

```console
./standalone.sh <domjudge URL>/api/contests <admin> <pwd> -p 72 13
```

For resolver at the end, run:

```console
./resolver.sh <domjudge URL>/api/contests <admin> <pwd> --presenter
```

To export stats of submissions and make `\solvestats` available in solutions tex files, run:
```console
bt solve_stats --api <domjudge URL> --username <admin> --password <pwd> (--contest-id 1) (--post-freeze)
```
