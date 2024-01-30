n = int(input())
suspects = [input() for _ in range(n)]

first_suspect_index = 0
second_suspect_index = 1

while second_suspect_index < n:
    print(f"? {suspects[first_suspect_index]} {suspects[second_suspect_index]}", flush=True)
    if input() == "OUI": # second_suspect is no longer a suspect
        second_suspect_index += 1
    else: # first_suspect is no longer a suspect
        first_suspect_index, second_suspect_index = second_suspect_index, second_suspect_index + 1

print("! " + suspects[first_suspect_index], flush=True)