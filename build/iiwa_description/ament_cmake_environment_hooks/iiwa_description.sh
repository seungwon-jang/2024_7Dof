# Gazebo classic
ament_prepend_unique_value GAZEBO_MODEL_PATH "$COLCON_CURRENT_PREFIX/share/iiwa_description/meshes"
ament_prepend_unique_value GAZEBO_RESOURCE_PATH "$COLCON_CURRENT_PREFIX/share/iiwa_description/meshes"

# Gazebo ignition and forward
ament_prepend_unique_value IGN_GAZEBO_RESOURCE_PATH "$COLCON_CURRENT_PREFIX/share/iiwa_description/meshes"
ament_prepend_unique_value GZ_SIM_RESOURCE_PATH "$COLCON_CURRENT_PREFIX/share/iiwa_description/meshes"
