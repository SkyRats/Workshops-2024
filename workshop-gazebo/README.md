# Using Gazebo for Simulation

In the sky, we use Gazebo as our simulator. There, we can employ different plugins to simulate sensors, cameras, and effectively construct our competition scenarios, for example. 

## Directory Organization

Gazebo organizes its files into directories such as `launch`, `models`, and `worlds`. These directories play crucial roles in managing simulation environments and customizations. All of these directories are in our simulation submodule `sky_sim`.

### Launch Directory

The `launch` directory contains launch files (.launch) that specify how to start and configure Gazebo simulations, including which world file to use and any additional parameters.

### Models Directory

The `models` directory stores files describing objects, robots, or any other entities that can be placed in the simulation environment. These models are often reused across different simulations. You can add yout own models (done in Blender for example).

### Worlds Directory

The `worlds` directory holds world files (.world) that define the environment in which simulations take place. It includes terrain, objects, lighting, and other elements necessary for creating realistic scenarios.

## SDF Files

SDF (Simulation Description Format) files are used to describe models, worlds, and other elements in Gazebo simulations. They contain XML-based markup specifying the properties, geometry, and behavior of entities within the simulation.

## Modifying Worlds and Including Custom Models

Users can modify existing world files or create new ones to tailor the simulation environment to their specific needs. Custom models can be included by adding their descriptions to the world file and ensuring their corresponding files are present in the `models` directory.

For example, let's include a custom model called `palm_tree`:

```xml
<model name="palm_tree">
  <!-- Define the start of a new model with the name 'palm_tree' -->
  
  <include>
    <!-- Include another model from a URI -->
    
    <uri>model://palm_tree</uri>
    <!-- Specify the URI of the model to include -->
    <!-- In this case, it imports the 'palm_tree' model from the 'model://palm_tree' path -->
  </include>
  
  <pose>10 10 0 0 0 0</pose>
  <!-- Set the position and orientation of the model -->
  <!-- This places the model at coordinates (10, 10, 0) with no rotation -->
  
  <static>true</static>
  <!-- Specify that the model is static and won't move during simulation -->
  
  <turnGravityOff>true</turnGravityOff>
  <!-- Indicate that gravity effects are turned off for this model -->
</model>
```
Now if we run in a terminal `roslaunch sky_sim sky_sim.launch`, we will see our new world:

<figure><img src="assets/gazebo.png" alt="" width="563"><figcaption><p><em>Drone and our new palm tree from the gazebo_vegetation package</em></p></figcaption></figure>

## Creating Custom Launch Files

Custom launch files can be created to automate and configure Gazebo simulations according to specific requirements. These files specify which world to load, what models to include, and any additional parameters necessary for the simulation setup.

By understanding the organization of directories, the structure of SDF files, and how to create custom launch files, users can effectively customize and control Gazebo simulations to meet their simulation needs.
