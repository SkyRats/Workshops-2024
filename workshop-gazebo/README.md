# Using Gazebo for Simulation

In the sky, we use Gazebo as our simulator. There, we can employ different plugins to simulate sensors, cameras, and effectively construct our competition scenarios, for example. 

## Directory Organization

Gazebo organizes its files into directories such as `launch`, `models`, and `worlds`. These directories play crucial roles in managing simulation environments and customizations.

### Launch Directory

The `launch` directory contains launch files (.launch) that specify how to start and configure Gazebo simulations, including which world file to use and any additional parameters.

### Models Directory

The `models` directory stores files describing objects, robots, or any other entities that can be placed in the simulation environment. These models are often reused across different simulations.

### Worlds Directory

The `worlds` directory holds world files (.world) that define the environment in which simulations take place. It includes terrain, objects, lighting, and other elements necessary for creating realistic scenarios.

## SDF Files

SDF (Simulation Description Format) files are used to describe models, worlds, and other elements in Gazebo simulations. They contain XML-based markup specifying the properties, geometry, and behavior of entities within the simulation.

## Modifying Worlds and Including Custom Models

Users can modify existing world files or create new ones to tailor the simulation environment to their specific needs. Custom models can be included by adding their descriptions to the world file and ensuring their corresponding files are present in the `models` directory.

## Creating Custom Launch Files

Custom launch files can be created to automate and configure Gazebo simulations according to specific requirements. These files specify which world to load, what models to include, and any additional parameters necessary for the simulation setup.

By understanding the organization of directories, the structure of SDF files, and how to create custom launch files, users can effectively customize and control Gazebo simulations to meet their simulation needs.
