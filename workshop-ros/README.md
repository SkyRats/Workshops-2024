## Creating a Workspace

At Sky, we have our own workspace, and therefore, this part of the workshop is important to keep a functional and organized working environment.

First of all, let's learn how to create a workspace \[1\]. Firstly, we create a directory with a `src` folder and run the `catkin_init_workspace` command within the `src` folder. This will automatically generate a `CMake` file, which will be the top-level of the workspace:

![Screenshot of the result of initializing the catkin workspace](images/workspace.png)

After that, we can issue the \`catkin_make\` command (outside of the \`src\` folder) to compile the workspace. This will create the other two folders we've discussed (\`build\` and \`devel\`) with various files inside. Feel free to explore what's in each one.

![Screenshot of the result of compiling the catkin workspace](images/resultado.png)

Every time we implement new features in our packages, we'll issue this command.

Additionally, the `source [ws_name]/devel/setup.sh` command should also be executed. This will add appropriate environment variables without us having to do it manually. If you've already installed ROS, you've likely executed this `source` command with the directory where ROS is installed on your computer.

## Packages

ROS is organized into packages that can contain source code, `launch` files, message definitions, data, and documentation.

As we've seen, our packages are located in the \`src\` folder of the workspace. Each package will have its own \`CMake\` files, but the `src` folder will have a main `CMake` file (Toplevel):

```bash
workspace_folder/        ## WORKSPACE
  src/                   ## SOURCE SPACE
    CMakeLists.txt       ## 'Toplevel' CMake file
    package_1/
      CMakeLists.txt     ## CMakeLists.txt file for package_1
      package.xml        ## Package manifest for package_1
    ...
    package_n/
      CMakeLists.txt     ## CMakeLists.txt file for package_n
      package.xml        ## Package manifest for package_n
```

But what are these \`CMake\` files? Basically, they describe the compilation rules for what is being compiled. It's important to note that each package can also have its own \`src\` folder, as well as folders for \`services\` and \`messages\`.

Furthermore, every package must have a \`package.xml\` file, which contains meta-information (name, version, description, license, dependencies, etc.).

Now that we know how to create packages that can integrate with ROS and leverage its functionalities, let's learn how to make use of this ecosystem.

```bash
catkin_init_workspace ## Initialize workspace, run inside src folder

catkin_make ## Build the workspace, run inside the ws

catkin build ## Build the workspace (allows other functionalities different from catkin_make, as we'll see later)

source [ws_name]/devel/setup.sh ## Add environment variables

catkin_create_pkg ## Create package, run inside src folder

## To create a ROS package, we need to declare its dependencies when creating it
```

## ROS Commands

For the next part of the workshop, we'll create an example workspace and package. For this, here's a summary of the important commands we'll use:

\| **Command** \| **Usage** \|
\|-------------\|-----------\|
\| `roscd` | Change ROS working directory \|
\| `rosrun` \| Run executable in an arbitrary package \|
\| `roscore` \| Run ROS master and other prerequisites \|
\| `rosnode` \| Display debug information about ROS nodes \|
\| `roslaunch` \| Launch ROS nodes locally and remotely via SSH \|
\| `roscp` \| Copy a file from one place to another \|

When in doubt, refer back to this table. During the workshop, it will become clearer when to use each one. We recommend some Cheat Sheets: 
[ROS Cheat Sheet Noetic](https://gomarketing.ottomotors.com/l/92812/2023-03-22/92z4ql/92812/1679526697SkoPBmzi/ROS_Cheat_Sheet_Noetic.pdf) 
[ROS Cheat Sheet](https://mirror.umd.edu/roswiki/attachments/de/ROScheatsheet.pdf).

**Curiosity**: \`rosrun\` can only start one node at a time from a single package, while \`roslaunch\` can start two or more nodes simultaneously from various packages. \`roslaunch\` will automatically start roscore (if it's not already running), unlike \`rosrun\`. \`roslaunch\` uses launch files, which can automatically start other programs including other launch files, set some parameters, etc. \`rosrun\`, on the other hand, does not use launch files - it starts nodes directly.
