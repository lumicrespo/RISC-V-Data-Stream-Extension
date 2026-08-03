#!/bin/bash

#usage bash generate_patch.sh <directory>

# Check if a directory was specified
if [ -z "$1" ]; then
    repo_dir="."
else
    repo_dir="$1"
fi

# Get the script's directory
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Check if the specified directory exists
if [ ! -d "$repo_dir" ]; then
    echo "Directory $repo_dir does not exist."
    exit 1
fi

# Change to the specified directory
cd "$repo_dir" || exit

# Check if the directory is a Git repository
if [ ! -d ".git" ]; then
    echo "Directory $repo_dir is not a Git repository."
    exit 1
fi


# Create a directory for patches in the script's directory if it doesn't exist
patch_dir="$script_dir/patch"
mkdir -p "$patch_dir"


# Include untracked files in the diff without fully staging them
git add -N .
# Generate a patch
patch_name="$patch_dir/DSE.patch"
git diff HEAD > "$patch_name"

# Remove the intent-to-add entries from the index
git reset > /dev/null