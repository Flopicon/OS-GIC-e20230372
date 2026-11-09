# Lab 2 — Linux Navigation and File Management: Individual Report

- **Student name/ID:** Hour Samnang / e20230372
- **Ubuntu username:** gic-hour-samnang
- **My values (`oslab values lab2`):**
  - file1 = `audit notes.txt`
  - file2 = `tax summary.txt`
  - owner = `Sales`
  - reader = `Engineering`
  - third = `HR`
- **Files:** `evidence/paths.txt`, `evidence/tree.txt`, `evidence/checkpoint.txt`

## What I Did

| Step | My command | Current folder when I ran it |
|---|---|---|
| Move the first file (relative destination) | `mv -- "$file1" ../reports/` | `~/oslab-work/lab2/incoming` |
| Move the second file (absolute paths) | `mv -- "$OSLAB_WORKSPACE/lab2/incoming/$file2" "$OSLAB_WORKSPACE/lab2/reports/"` | `~/oslab-work/lab2` |
| Read the report from my reader department (relative path) | `cat "../$owner/$file1"` | `~/oslab-work/lab2/TechCorp/Engineering` |
| The path error I made on purpose, and its message | `cat "reports/$file1"` — No such file or directory | `~/oslab-work/lab2/TechCorp/Engineering` |
| The relative path that fixed it | `../../reports/audit notes.txt` | `~/oslab-work/lab2/TechCorp/Engineering` |

## Explanation

A correct file name can still give a "No such file or directory" error because Linux looks for the file relative to the current working directory when using a relative path. If the path does not point to the correct location, the command cannot find the file even if it exists somewhere else. The `mv` command moves a file from one location to another, while `cp` creates a copy and keeps the original file. For example, I used `mv` to move my two reports into the `reports` folder, then used `cp` to copy them into `TechCorp/Sales` while keeping the original reports.

## What My Tests Do Not Prove

`ls` only shows the names of files and folders, but it does not prove that their contents are identical. `cmp` compares two files byte by byte, so it can confirm that the copied reports have exactly the same contents as the originals.

## Plus / Challenge



## AI Note (optional)


