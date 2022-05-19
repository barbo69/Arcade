# A standard procedure on how to collaborate

To allow better code tracability and understanding, commits can be attached to issues, pull requests, etc.

## TLDR

Steps to reproduce:
1. Assign the [issue](https://github.com/EpitechPromo2025/B-OOP-400-LYN-4-1-arcade-baptiste.barbotin/issues) you're working on to yourself, if not already done.
2. Create a branch named `ISSUE_NUMBER-ISSUE_TITLE`
3. When commiting:
    1. add `#ISSUE_NUMBER` at the end of you commit. Don't forget to put a space before the `#` symbol.
You can also use this inside your code comments. [#9](https://github.com/EpitechPromo2025/B-OOP-400-LYN-4-1-arcade-baptiste.barbotin/issues/9)
4. When some work has been done
    1. push the branch
    2. create a _draft_ pull request. Draft indicates that the work is not ready yet.

5. When you're done working on the issue:
    1. mark the pull request as ready.
    2. If necessary, wait for a review
    3. Merge the pull request using rebase strategy.

6. Mark the issue as closed.

## Clean commit messages:
-   Always refer your commit to an issue
-   You can use [gitmoiji](https://gitmoji.dev/) to have more readable commits