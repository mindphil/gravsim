#include <iostream>
#include <vector>
#include <cmath>

// Simple 2D point
struct Vec2 {
    double x, y;
    
    Vec2(double x = 0, double y = 0) : x(x), y(y) {}
    
    Vec2 operator+(const Vec2& other) const { return Vec2(x + other.x, y + other.y); }
    Vec2 operator-(const Vec2& other) const { return Vec2(x - other.x, y - other.y); }
    Vec2 operator*(double s) const { return Vec2(x * s, y * s); }
    
    double length() const { return sqrt(x*x + y*y); }
};

// position, velocity, and mass
struct Body {
    Vec2 pos, vel;
    double mass;
    
    Body(Vec2 position, Vec2 velocity, double m) 
        : pos(position), vel(velocity), mass(m) {}
};

// Calculate gravitational force between two bodies
Vec2 gravity_force(const Body& a, const Body& b) {
    Vec2 r = b.pos - a.pos;           // Vector from a to b
    double dist = r.length();
    
    if (dist < 0.01) return Vec2(0, 0);  // Avoid division by zero
    
    double G = 1.0;  // Simplified gravitational constant
    double force_mag = G * a.mass * b.mass / (dist * dist);
    
    // Unit vector * force magnitude
    return Vec2(r.x/dist, r.y/dist) * force_mag;
}

int main() {
    // Create two bodies
    std::vector<Body> bodies = {
        Body(Vec2(-1, 0), Vec2(0, 0.5), 1.0),   // Body 1
        Body(Vec2(1, 0), Vec2(0, -0.5), 1.0)    // Body 2
    };
    
    double dt = 0.01;  // Time step
    
    std::cout << "Time,Body1_X,Body1_Y,Body2_X,Body2_Y" << std::endl;
    
    // Simple simulation loop
    for (int step = 0; step < 1000; step++) {
        
        // Calculate forces and update velocities
        for (int i = 0; i < bodies.size(); i++) {
            Vec2 total_force(0, 0);
            
            // Sum forces from all other bodies
            for (int j = 0; j < bodies.size(); j++) {
                if (i != j) {
                    total_force = total_force + gravity_force(bodies[i], bodies[j]);
                }
            }
            
            // F = ma, so a = F/m
            Vec2 acceleration = total_force * (1.0 / bodies[i].mass);
            
            // Update velocity: v = v + a*dt
            bodies[i].vel = bodies[i].vel + acceleration * dt;
        }
        
        // Update positions: x = x + v*dt
        for (auto& body : bodies) {
            body.pos = body.pos + body.vel * dt;
        }
        
        // Output every 10 steps
        if (step % 10 == 0) {
            std::cout << step * dt << ","
                      << bodies[0].pos.x << "," << bodies[0].pos.y << ","
                      << bodies[1].pos.x << "," << bodies[1].pos.y << std::endl;
        }
    }
    
    return 0;
}