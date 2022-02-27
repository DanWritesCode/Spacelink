# Spacelink

Identify duplicate files on a Linux filesystem and generate a script to hardlink them.

## How it works

- Scans the _source_ folder and maps out their file names, file sizes, and index nodes (inodes) on the drive
- Checks the _scan_ folder for files with an _identical name and file size_
  - This method of detection is not as reliable as a file hash check, however, for the use case it is likely fine (see case study)
  - The inode of the file in the scan folder is compared to the inode inside the map (from the _source_ folder)
    - If the inode matches, the file is already a hard link and is _ignored_
    - If the inode does _not_ match, the file is noted as a duplicate
- All identified duplicate files get de-duplication instructions written to the output file, which will look similar to the following:
  - `rm 'scanFilename'`
  - `ln 'sourceFilename' 'scanFilename'`

## Usage Instructions

1) Use cmake to create the makefile:
   `cmake .`
2) Use the make utility to generate the binary:
   `make`
3) Run the binary: 

`./spacelink --source <path> --scan <path> --output <file name>`

- The _source_ folder contains the original files you want to _keep_
- The _scan_ folder contains the duplicates you want to remove and replace with hardlinks
- The _output_ file is the path where the de-duplication script is written to. This can be anywhere on your filesystem, and doesn't have to match the folders you're scanning.
- Do not include trailing slashes on source or scan arguments

## Case Study

- Transmission (a download client) downloaded large files to `/downloads`
- Plex Media Server had a library on the folder `/tv`
- A third application (Sonarr) detects new files in `/downloads` and hard-links them to `/tv`
- Due to permission issues, Sonarr _copied_ the files from downloads rather than hard-linking them
- This resulted in unneccassary duplicate data being written to the drive
- After consolidating the files using Spacelink, over **47 GB** of disk space was saved
