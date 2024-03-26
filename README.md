# KARWa 2024: Problemset

Problemset for the first edition of KARWa.

This uses [Ragnar's awesome BAPCtools scripts](https://github.com/RagnarGrootKoerkamp/BAPCtools).

## Building problemset

Assuming you already have BAPCtools installed, simply run:

```console
bt pdf
```

This will create a `contest.pdf` document, with the full problemset.

If you don't want to figure out what LaTeX's cryptic error messages mean, you can install the `texlive-full` metapackage on most Linux distros.
This should fix most problems you may have!

## Testing

To make sure all the sample & secret testcases work correctly, run:

```console
bt run
```

## Problem expected difficulty (from bottom to top)
### Hard
- Bombe
- 24H vélo

### Medium
- Flot
- SNCB
- Ping-pong
- Pairmutation

### Easy
- Meurtrier
- Antennes
- Tomates
