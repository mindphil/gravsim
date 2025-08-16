# Gravity Simulation

A 2D gravitational n-body physics simulator written in C++.

## Features

- **2D Physics**: Simple Newtonian gravity simulation with position, velocity, and mass
- **N-Body System**: Calculate forces between multiple bodies
- **CSV Output**: Exports position data for analysis/plotting
- **Modular Design**: Separate physics engine and visualization components

## Current Implementation

The simulation uses basic Euler integration with:
- Gravitational force calculation: `F = G * m1 * m2 / r²`
- Newton's second law: `F = ma`
- Position/velocity updates each timestep

**Example Output**: Two bodies in circular orbit around their center of mass.

## Building

Requires CMake 3.20+, Clang, and GLFW.

```bash
# Configure and build
cmake --preset=default
cmake --build --preset=default

# Run physics simulation
./build/main

# Run visualization (in development)
./build/vis
```

## Project Structure

```
gravsim/
├── src/
│   ├── main.cpp      # Physics simulation with CSV output
│   └── vis.cpp       # GLFW visualization (in progress)
├── CMakeLists.txt    # Build configuration
└── CMakePresets.json # Build presets
```

## Roadmap

- [ ] **GLFW Visualization**: Real-time rendering of bodies and trajectories
- [ ] **Collision Detection**: Elastic/inelastic collisions between bodies  
- [ ] **Better Integration**: Runge-Kutta or Verlet integration for stability
- [ ] **Interactive Controls**: Add/remove bodies, adjust parameters
- [ ] **Performance**: Spatial partitioning for large N-body simulations

## Physics Notes

- Gravitational constant `G = 1.0` (simplified units)
- Time step `dt = 0.01` (may need adjustment for stability)
- Collision avoidance: Forces capped at minimum distance 0.01
- Current method: Euler integration (first-order, may drift over time)
