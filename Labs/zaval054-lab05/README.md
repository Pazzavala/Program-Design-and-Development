# 3081 Lab 5: Code Styling
_(Due: Thursday, October. 12, 2023 @ 11:59pm)_

## What You Will Learn

1. What a styleguide and Linter is
2. Write your code in Google format style.

## General Information

### What are Linters and Styleguides
A linter is a static code analysis tool that helps users(developers) flag style errors, bugs, and bugs. For the purpose and uses in this lab, we will mainly see it flag style errors.

A style guide is a set of guidelines for a developer to help neatly write their code so that the code is more legible, and every member of a team is not writing code in their own way.

### CPP Lint and Google StyleGuide ###
CPPlint is an open source software written in python that enforces Googles C++ style guide. [Link to the CPPlint Repo](https://github.com/cpplint/cpplint) 

[Google's C++ Style Guide](https://google.github.io/styleguide/cppguide.html) is Google's public style guide that they use for their C++ code and is what they have determined to like. Other companies/schools like our class, have chosen to use this style guide, though it is not the only one. As you get into industry you will work for companies that have their own "flavor" of styling their code, much like how you have a different style to your classmates.
### Accessing a Lab Machine

For this assignment, we suggest you use a lab machine in ***Keller Hall 1-250*** or ***Keller Hall 1-262*** ([details](https://cse.umn.edu/cseit/classrooms-labs#cselabs)), as Git is already installed on these machines. You can also access a lab machine remotely using [SSH](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/SSH/README.md) or a web-based service called [VOLE](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/VOLE/README.md). You will use your CSE Labs account to login to the lab machines. If you do not already have an account, create the account following these [instructions](https://wwws.cs.umn.edu/account-management).


**IMPORTANT: Inside the lab machine, only files saved to your home folder (e.g., `/home/lorim007`) will persist across sessions. If you log out, make sure your progress is pushed to GitHub or saved in the home folder.**

**IMPORTANT: One of the reasons you might not be able to log into a lab machine is that you reached your CSE Labs Account disk quota. To free space, please use these [instructions](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/CSE%20Disk%20Quota%20Exceeds/README.md). (In some cases, you might need to SSH into a CSE classroom or lab machine to complete the instructions.)**

### Retrieve Class Materials

1. Clone your personal repository for the lab. **Replace the x500 with your personal x500.**
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-f23/x500-lab05.git
    ```
### What's in lab05 folder?

<ul>
  <li>  <code>README.md</code>
  <li>  <code>.gitignore</code>
  <li>  <code>app</code> folder, which contains:
    <ul>
      <li>  <code>graph_viewer</code> : producing graph visualization
      <li>  <code>transit_service</code> : visualization
    </ul>
  <li>  <code>libs</code> folder, which contains:
    <ul>
      <li>  <code>routing</code> : finding the paths
      <li>  <code>transit</code> : entities properties
    </ul>
  <li>  <code>dependencies</code>
</ul>

## Lab Instructions

### CPPLint

You will be refactoring some of the codes inside `libs/transit/` folder to match the Google code style while maintaining the project structure.

1. Before everything, try to run the program and see whether it worked or not. You can run the program just as you did during the lab04. If it doesn't work, let the TAs know.

2. Before proceeding, make sure you are in top folder and not inside the libs folder.
Run cpplint onto one of the `libs/transit/src` files (`Drone.cc`)
    ```
    cpplint --filter=-legal/copyright,-build/include,-build/namespaces,-runtime/explicit,-build/header_guard,-runtime/references,-runtime/threadsafe_fn ./libs/transit/src/Drone.cc
    ```

    *Note: `--filter` flag means exclude what we do not want to check.*

3. It will produce multiple errors similar to the results below:

    ```
    cpplint --filter=-legal/copyright,-build/include,-build/namespaces,-runtime/explicit,-build/header_guard,-runtime/references,-runtime/threadsafe_fn ./libs/transit/src/Drone.cc
    ./libs/transit/src/Drone.cc:8:  Missing space after ;  [whitespace/semicolon] [3]
    ./libs/transit/src/Drone.cc:12:  Missing spaces around =  [whitespace/operators] [4]
    .
    .
    .
    .
    ./libs/transit/src/Drone.cc:72:  Missing space before ( in if(  [whitespace/parens] [5]
    ./libs/transit/src/Drone.cc:72:  Missing space before {  [whitespace/braces] [5]
    Done processing ./libs/transit/src/Drone.cc
    Total errors found: 17
    ```

4. This means there are 17 errors in the Drone.cc which doesn't match the Google code style guide.

5. Try to fix this until there is 0 error left.
    ```
    Done processing ./libs/transit/src/Drone.cc
    Total errors found: 0
    ```

6. For the next steps you can clean up the code manually or you can refer to the [VS Code Linting Plugin](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/VSCode%20CPPLint/README.md) to clean your code automatically.

7. Repeat the steps above for **all the files** inside the `libs/transit/src` and `libs/transit/include` **excluding** the `math` and `util` folders until there are **0** errors left. You can run the cpplint for all of the files inside the `libs/transit/src` and `libs/transit/include` with the command below.
    ```
    cpplint --filter=-legal/copyright,-build/include,-build/namespaces,-runtime/explicit,-build/header_guard,-runtime/references,-runtime/threadsafe_fn ./libs/transit/src/* ./libs/transit/include/* 
    ```

8. Rerun the simulation and see if the drone and robots are still being generated. If not, something went wrong while you were cleaning up the code. Try to fix this first before submitting. If it work as usual, you are good to go.

Now you have completed your lab!!!
So push all of your works to github (if you forgot how to push to github, check lab 1 again) and follow the instruction below in the `Final Submission`.

### VSCode Linting integration ###
You can set up visual studio code to "do" the linting for you while you code. A quick readme on how to do this can be found [here](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/VSCode%20CPPLint/README.md) in the classes FAQ.

## Final Submission
To submit your assignment, post on the Gradescope assignment "Lab 5: Code Styling" your team repo link and the final commit ID for your submission.
Click [here](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/Commit%20ID/README.md) to see how to get commit id.
