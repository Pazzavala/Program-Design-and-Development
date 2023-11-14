# 3081 Lab 10: Import Assets
_(Due: Thursday, November 16th, 2023 @ 11:59pm)_

## General Information

### Accessing a Lab Machine
For this assignment, we suggest you use a lab machine in ***Keller Hall 1-250*** or ***Keller Hall 1-262*** ([details](https://cse.umn.edu/cseit/classrooms-labs#cselabs)), as Git is already installed on these machines. You can also access a lab machine remotely using [SSH](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/SSH/README.md) or a web-based service called [VOLE](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/VOLE/README.md). You will use your CSE Labs account to login to the lab machines. If you do not already have an account, create the account following these [instructions](https://wwws.cs.umn.edu/account-management).

**IMPORTANT: One of the reasons you might not be able to log into a lab machine is that you reached your CSE Labs Account disk quota. To free space, please use these [instructions](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/CSE%20Disk%20Quota%20Exceeds/README.md). (In some cases, you might need to SSH into a CSE classroom or lab machine to complete the instructions.)**

## Overwritten Unique Changes

All students are given the same base code for labs which are the solutions to the previous lab. If you had any personal changes or implementations in previous labs that you want carried forward to the current or future labs, those changes will need to be manually copied over by you, the developer.

## Retrieve Class Materials
1.  Clone your teams **private lab10** repository<br>
    *Note: **replace** Team-XXX-X with your lecture section and team number* <br>
    *Example: Team-001-1-lab10*
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-f23/Team-XXX-X-lab10.git
    ```


### What's in lab10 folder?

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
  <li> <code>docs</code>: Doxygen documentation files
  <li> <code>dependencies</code>
</ul>

### Dockerfile
Now that you're familiar with using docker to build and run your project outside of school lab machines (yay!) we've included a `Dockerfile` for you to use.
Here is a link to the workshop-5 writeup for docker resources. [**Workshop-5 Link**](https://github.umn.edu/umn-csci-3081-f23/public-workshop5)

Here are some commands that may be useful:
- For building the simulation container
   ```bash
   $ docker builds -t <image_name> .
   ```
- For running the built container
   ```bash
   $ docker run --rm -it -p <hostport>:<containerport> <image_name>   
   ```

## Lab Instructions

### Goal
  **The primary goal of this lab is for you to know how to add assets (i.e., models) into the simulation and prepare you for the final project.**

## Tasks
| ID | Title | Task Summary Description | Task Deliverable |
| :---: | --- | --- | --- |
| Task 1 | Assets | Add helicopter to the simulation | Source Code |
| Task 2 | Assets | Add human to the simulation | Source Code |
| Task 3 | Create Button | Create button on webpage (front-end) to support the creation of multiple humans | HTML and Javascript |
| Task 4 | Assets | Implement your own idea | Source Code |
| Task 5 | Doxygen | Create documentation of the classes/functions that you create | HTML/Source Code |
| Task 6 | Code Styling | Match your code style with Google style guidelines | Source Code |

# Tasks
### Task 1 (Helicopter)
Steps:
1. Download the helicopter model from either [class github](https://github.umn.edu/umn-csci-3081-f23/ProjectAssets) or other sources like [sketchfab](https://sketchfab.com/)
   - *Important: File must be .glb format*
2. Place the helicopter model under `<project>/apps/transit_service/web/assets/model/` folder.
3. Create the `Helicopter` entity class. This class will do nothing except moving from its position towards a random destination. After the helicopter reaches its destination it will choose a new random destination, and repeat.
   - This helicopter can move freely without using any path restrictions (i.e, no need to use Astar, Dijkstra, DFS, BFS).
   - XYZ Bounding:
        ```
        -1400 < x < 1500
         240  < y < 600
        -800  < z < 800
        ```
4. Add `HelicopterFactory` to the existing composite factory design pattern. ([See Lab07 for a refresher](https://github.umn.edu/umn-csci-3081-f23/public-lab07))
   - `type: "helicopter"`
5. When a browser connects to the webserver, it will load the `umn.json` file which can be found under `<project>/apps/transit_service/web/scenes/umn.json`
6. Add a new json object inside the umn.json to **create** a helicopter right at the start of the scene with the followings info (Note: replace mesh, position, and scale according to your model's choice):
   ```json
    "type": "helicopter",
    "name": "Helicopter",
    "mesh": "assets/model/helicopter.glb",
    "position": [x, y, z],
    "scale": [xScale, yScale, zScale],
    "rotation": [0, 0, 0, 0],
    "direction": [1,0,0],
    "speed": 50.0,
    "offset": [0, 0.6, 0]
   ```
   `mesh` = model file location<br>
   `position` = your choice as long as it's within the map <br>
   `scale` = make it look like real life size (i.e., not too small or too large)
7. If you did all of the steps above correctly, now the helicopter should be created and moving around as soon as you start the webpage.

### Task 2 (Human)
Steps:
1. Download the Human model from either [class github](https://github.umn.edu/umn-csci-3081-f23/ProjectAssets) or other sources.
   - *Important: File must be .glb format*
2. Place the human model under `<project>/apps/transit_service/web/assets/model/` folder.
3. Create the `Human` entity class. This class will do nothing except moving from its position towards a random destination. After the human reaches its destination it will choose a new random destination, and repeat.
   - **Must use Astar strategy to move around**
   - XYZ Bounding:
        ```
        -1400 < x < 1500
         240  < y < 300
        -800  < z < 800
        ```
4. Create and add `HumanFactory` to the existing composite factory design pattern.
   - type: "human"
5. When a browser connects to the webserver, it will load the `umn.json` file which can be found under `<project>/apps/transit_service/web/scenes/umn.json`
6. Add a new json object inside the umn.json to **create** a human right at the start of the scene with the followings info (Note: replace mesh, position, and scale according to your model's choice):
      ```json
      "type": "human",
      "name": "Human-OG",
      "mesh": "assets/model/human.glb",
      "position": [498.292, 270, -228.623],
      "scale": [0.005, 0.005, 0.005],
      "rotation": [0, 0, 0, 0],
      "direction": [1,0,0],
      "speed": 10.0,
      "radius": 1.0,
      "start": 2.0,
      "duration": 2.0,
      "offset": [0, -0.5, 0]
      ```
      `mesh` = model file location<br>
      `position` = your choice as long as it's within the map <br>
      `scale` = make it look like real life size (i.e., not too small or too large)
7. If you did all of the steps above correctly, now the helicopter should be created and moving around as soon as you start the webpage.

### Task 3 (Create Button)
Steps:
1. You will need to modify some HTML and Javascript for this task.
2. HTML will be used to display the button to the users and Javascript will be used to move the data from the front-end (webpage) to the back-end (C++ server).
3. The button will be created under the schedule page which can be found at `<project>\apps\transit_service\web\schedule.html`
4. We want to create a `Add Human` button below the Schedule Delivery map. So, first find the location of the `Schedule Delivery` button (line 71).
5. Under the schedule delivery button, create a button which displays `Add Human` and it will call `addHuman()` function.
   - Button syntax:
      ```html
      <button onclick='function()'>Text to Display</button>
      ```
   - `onclick='function()'`: When the button is clicked, it will call the given function. 
6. Optional: If you are already an expert in front-end and would like to make cool designs of the button, you are welcome to do so.
7. Inside the script element, create a function which will use the api to send the data to the back-end. The function name must be `addHuman()` to match with step 5. As a guide, check out the `function schedule() {...}` on how to create a function using Javascript.
8. First declare humanID inside the script element.
   ```
   var humanID = 1;
   ```
9. Inside this `addHuman()` function, first call the api to create an entity with the following json data (you might want to modify the mesh, position, and scale as you see fit):
      ```json
      "type": "human",
      "name": "Human-"+humanID,
      "mesh": "assets/model/human.glb",
      "position": [700, 290, 400],
      "scale": [xScale, yScale, zScale],
      "rotation": [0, 0, 0, 0],
      "direction": [1,0,0],
      "speed": 10.0,
      "radius": 1.0,
      "start": 2.0,
      "duration": 2.0,
      "offset": [0, -0.5, 0]
      ```
      `mesh` = model file location<br>
      `scale` = make it look like real life size (i.e., not too small or too large)
10. Add `humanID += 1` after you call the api as this will increment the human ID.

11. If you did all the steps above correctly, a human will spawn if you click `Add Human` button. _If you are still having troubles, check out `schedule.html:142` where we send the messages to the backend to create the package and robot for scheduling a delivery._

### Task 4: Implement your own idea
For this task, create at least **one** new entity of your own choice and you can decide what you want this entity to do. This entity should **at least** created once when the simulation starts. *Be creative as much as possible*.

**Important: Your entity should be doing something.**

Example ideas:
   - High speed jetplane or sports car
   - Kangaroo hopping when traveling to the destination
   - Random cars driving to add life to the simulation

### Task 5 (Doxygen)
Write Doxygen for all the **NEW** classes you create (public members only). Which in our case for this lab, are as follows:
- Helicopter
- HelicopterFactory
- Human
- HumanFactory

### Task 6 (Code Style)
Match your new code's style with Google Code Styling guide. Which in our case for this lab, is as follow:
- Helicopter
- HelicopterFactory
- Human
- HumanFactory

## Final Submission

To submit your assignment, post on the Gradescope assignment "Lab 10: Import Assets" your team repo link and the final commit ID for your submission.
Click [here](https://github.umn.edu/umn-csci-3081-f23/FAQ/blob/main/Commit%20ID/README.md) to see how to get commit id.
