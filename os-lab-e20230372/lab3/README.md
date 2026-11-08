# Lab 3 — Wildcards, Hard Links and Symbolic Links: individual report

Copy this template to `lab3/README.md` in your own course repository. Follow [the instructions](lab3-instruction.md). Your prediction, debrief and checkpoint answers are already saved by `oslab`; do not copy them here. The marks come from those records and your evidence files; this report is your own record of the lab.

- Student name/ID: Hour Samnang / e20230372
- Ubuntu username: gic-hour-samnang
- My values (`oslab values lab3`): name = lemon, tag =  final, v1 = 465, v2 = 514
- Files: `evidence/wildcards.txt`, `evidence/links.txt`, `evidence/replacement.txt`, `evidence/checkpoint.txt`

## What I Saw

| State | What `cat` printed for the hard link | What `cat` printed for the symbolic link | What `readlink` printed |
|---|---|---|---|
| Before the rename | version 465 | version 465 | lemon.txt |
| After the rename, before the repair | version 465 | error | lemon.txt |
| After a new file took the old name | version 465 | version 514 | lemon.txt |
| After my repair | version 465 | version 465 | lemon-final.txt |

My repair (the two commands I wrote):
rm -- "$name-soft.txt"
ln -s "$name-$tag.txt" "$name-soft.txt"
## Explanation

`oslab debrief lab3` records which prediction answers you confirmed and which you corrected. Here, in 3–5 sentences for yourself: why did the symbolic link read `version <v2>` after the new file took the old name, while the hard link still read `version <v1>`? Use your own inode numbers from `evidence/replacement.txt`.
A hard link points to the same inode as the original file, while a symbolic link stores a file path.
After renaming lemon.txt to lemon-final.txt, the symbolic link could no longer find its original target, but the hard link could still access the original file.
When I created a new lemon.txt, the symbolic link followed that filename and read version 514, while the hard link continued reading version 465.
The original file and hard link shared inode 18752072, while the new lemon.txt had a different inode, 18752312.
## What My Tests Do Not Prove

One or two sentences. Think about what `cat` shows and what only `ls -li` shows.
The cat command only shows the file contents.
The ls -li command shows inode numbers, which allows us to verify whether files share the same inode.
## Plus / Challenge (only if you did them)

Your bracket-pattern answer, or your link counts.

## AI Note (optional)

One suggestion an AI tool gave you and the test you used to check it.
