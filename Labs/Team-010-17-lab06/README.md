# 3081 Lab 6: Doxygen
_(Due: Thursday, October. 19th, 2023 @ 11:59pm)_

## General Information

### What is Doxygen?

Doxygen serves as a documentation generation tool. It doesn't directly generate the documentation; instead, it provides a syntax that developers utilize to write documentation within the source/header files. Doxygen then processes these comments to produce a range of documentation artifacts. These artifacts encompass API documentation, code structure, call graphs, class hierarchies, file and directory structures, to name just a few.

Doxygen is a highly configurable tool that is used by [many projects](https://www.doxygen.nl/projects.html), but we will be going over a few of the basics in this lab.

### Goal
The primary goal of this lab is for you to familiarize yourself with Doxygen and learn to write documentation in a specific syntax so that Doxygen can automatically generate HTML documentation.

### Accessing a Lab Machine
For this assignment, we suggest you use a lab machine in ***Keller Hall 1-250*** or ***Keller Hall 1-262*** ([details](https://cse.umn.edu/cseit/classrooms-labs#cselabs)), as Git is already installed on these machines. You can also access a lab machine remotely using [SSH](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/SSH/README.md) or a web-based service called [VOLE](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/VOLE/README.md). You will use your CSE Labs account to login to the lab machines. If you do not already have an account, create the account following these [instructions](https://wwws.cs.umn.edu/account-management).

**IMPORTANT: One of the reasons you might not be able to log into a lab machine is that you reached your CSE Labs Account disk quota. To free space, please use these [instructions](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/CSE%20Disk%20Quota%20Exceeds/README.md). (In some cases, you might need to SSH into a CSE classroom or lab machine to complete the instructions.)**

## Retrieve Class Materials
1.  Clone your teams **private Lab06** repository<br>
    *Note: **replace** Team-XXX-X with your lecture section and team number* <br>
    *Example: Team-001-1-lab06*
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-f23/Team-XXX-X-lab06.git
    ```


### What's in Lab06 folder?

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


1. Navigate to your lab repo
    ```bash
    $ cd <path_to_directory>
    ```
2. Create the configuration file.

    To start generating documentation, you must first generate a Doxygen
    configuration file in the docs directory. Run the following command from the
    lab06 directory (where this README is).

    ```
    $ mkdir docs
    $ doxygen -g docs/Doxyfile
    ```
    *Note: `mkdir` is used to create directory*

    You will now see a new file **Doxyfile** in the <code>docs</code> directory.

3. Modify the Doxyfile to look in the <code>libs</code> folder when compiling (i.e, only the folder that was set as an Input will get the examination from doxygen). You can do this by setting the **INPUT** tag of your **Doxyfile**. Since this lab required you to write doxygen for only certain files/classes, you would need to point the Input to <code>libs/</code>. It should be around `line 832` within `Doxyfile`.

    ```
    INPUT                  = "../libs/"
    ```

    You would also want to set **RECURSIVE** tag of your **Doxyfile** to YES so that all the codes inside the folder you set for the input will be taken account for. Locate to `line 911` within `Doxyfile`.

    ````
    RECURSIVE              = YES
    ````
    
    Now, set the **EXCLUDE** tag to parsers and util folder. This tag is used if you do not want the doxygen to look at the provided path folders. You can find the EXCLUDE tag around `line 920`.
    ````
    EXCLUDE                  = "../libs/transit/include/util" "../libs/routing"
    ````

    The path is relative to the directory from which you run/compile the doxygen. ***It is important that you set it up to run from `docs/`***. Doxygen will not inform you if it does not find the src directory -- it just won't generate any files from your classes.


4. Generate the html pages for this lab. Run the following commands:
    ```bash
    $ cd docs
    $ doxygen Doxyfile
    ```
    You can now view the generated documentation from the `index.html` file in the
    `html` directory that was generated inside the docs folder. Open the `index.html` page which is refered to as the *landing page*. Explore the various menus to see how the comments in the code are organized in the html. Hover on the Classes menu and click on `Class List`. Here, you will see different classes.

5. Now modify the `/libs/transit/include/Drone.h` file to add Doxygen comments.
  
    Use **@brief** to describe the class, **@param** to describe the parameter, and **@return** to specify a function's return values. You can also refer to Doxygen's [manual](https://doxygen.nl/manual/docblocks.html) for their commenting standards.

    Example,
    ```
    /**
     * @brief The summation of two numbers.
     * 
     * @param a First number.
     * @param b Second number.
     * @return Result of adding two number.
     **/
    float sum(float a, float b) {
      return a+b;
    }
    ```

6. Files that you would need to document using doxygen (Doxygen documentation only needs to be written for header files):
    - /libs/transit/include/
      - Drone.h
      - IController.h
      - IEntity.h
      - Package.h
      - SimulationModel.h

    For this lab, we don't expect you to know exactly how each function and class in each of these files works, but we expect you to document **WHAT** each function/class does.

7. After you have written everything, recompile the doxygen (step 4) and click on the `classes` menu. If all the classes and its methods are displayed similar to the `Vector3 class`, then you are completed this lab.
8. Push all of your work to your github repo and follow the submission below.
<br>

## Final Submission

To submit your assignment, post on the Gradescope assignment "Lab06: Doxygen" your team repo link and the final commit ID for your submission.
Click [here](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/Commit%20ID/README.md) to see how to get commit id.
