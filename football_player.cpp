#pragma once // Header guard to prevent multiple inclusion

#include <vector> // #include directive
#include <string>

// namespace to group related identifiers
namespace FootballPlayer {
    // Abstract base class for Movement behavior
    class Movement {
        public:
            virtual void move() = 0;
            virtual ~Movement() = default; // Destructor; virtual function to clean up derived classes when object is deleted
    };
    
    // Run: Move in given direction at given speed; use angleFacing and movementSpeed
    class Run : public Movement {
        public:
            void move() override;
    };
    
    // Stationary: Move in no direction; use angleFacing
    class Stationary : public Movement {
        public:
            void move() override;
    };

    // TackleMovement: Leap forward in direction character is facing; use angleFacing and movementSpeed; how to show collision?
    class TackleMovement : public Movement {
        public:
            /// Specific movement behavior for a tackle
            void move() override {
                // Specific movement behavior for a tackle
            }
    };

    // BlockMovement: Move sideways in direction character was moving, now facing nearest opponent; use angleFacing and movementSpeed
    class BlockMovement : public Movement {
        public:
            /// Specific movement behavior for a tackle
            void move() override {
                // Specific movement behavior for a tackle
            }
    };

    // SlideMovement: Slide forward in direction character was moving; use angleFacing and movementSpeed
    class SlideMovement : public Movement {
        public:
            /// Specific movement behavior for a tackle
            void move() override {
                // Specific movement behavior for a tackle
            }
    };
    
    // Abstract base class for Action behavior
    class Action {
        public:
            virtual void act() = 0;
            virtual ~Action() = default; // Destructor; virtual function to clean up derived classes when object is deleted
    };
    
    // Pass: Pass the ball to player on same team; use angleFacing
    class Pass : public Action {
        public:
            void act() override;
    };
    
    // Tackle: Activate TackleMovement movement
    class Tackle : public Action {
        public:
            void act() override;
    };
    
    // Block: Activate BlockMovement movement
    class Block : public Action {
        public:
            void act() override;
    };
    
    // Slide: Activate SlideMovement movement
    class Slide : public Action {
        public:
            void act() override;
    };
    
    // FootballPlayer class uses delegation via composition
    class FootballPlayer {
        public:
            FootballPlayer(Movement* m, Action* a); // Delegation
        
            void move();
            void act();
            void setAngleFacing(float angle);   // setter
            float getAngleFacing() const;       // getter
        
        private:
            Movement* movement;
            Action* action;
            std::string name;
            int age;
            int team;
            Position position;
            float angleFacing; // in degrees (0 = right, 90 = up, etc.)
            int movementSpeed;
    };

    void FootballPlayer::setAngleFacing(float angle) {
        // Optionally normalize to [0, 360)
        angleFacing = fmod((angle >= 0 ? angle : angle + 360.0f), 360.0f);
    }
    
    float FootballPlayer::getAngleFacing() const {
        return angleFacing;
    }

    // Position on xy plane
    struct Position {
        int x;
        int y;
    
        Position(int xVal = 0, int yVal = 0) : x(xVal), y(yVal) {}
    };
}
