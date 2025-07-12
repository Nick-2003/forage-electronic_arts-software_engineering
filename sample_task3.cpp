#pragma once

#include <vector>

/////////////////////////
// Locomotion Strategy //
/////////////////////////

// This is the first of the strategy patterns - if you are unfamiliar with
// the strategy design pattern, consult this reference:
// https://refactoring.guru/design-patterns/strategy

class Locomotion {
public:
    virtual void move() = 0;
};

class Swim : Locomotion {
public:
    void move() override;
};

class Crawl : Locomotion {
public:
    void move() override;
};

class Stationary : Locomotion {
public:
    void move() override;
};

/////////////////////
// Action Strategy //
/////////////////////

// Another implementation of a strategy pattern - here we delegate the various ways
// a sea creature can behave to their own classes. That way multiple creatures can
// depend on the same behavior - several fish can blow bubbles, for example.

class Action {
public:
    virtual void act() = 0;
};

class BlowBubble : Action {
public:
    void act() override;
};

class PuffUp : Action {
public:
    void act() override;
};

class ChangeColor : Action {
public:
    void act() override;
};

///////////////////////
// Resource Strategy //
///////////////////////

// the final implementation of the strategy pattern

class Resource {
public:
    virtual void collect() = 0;
};

class Pearl : Resource {
public:
    void collect() override;
};

class Shell : Resource {
public:
    void collect() override;
};

class FishFillet : Resource {
public:
    void collect() override;
};

//////////////////////////////
// Sea Creature Composition //
//////////////////////////////

// Here we tie everything we've built together in a single class.
// Note that in order to reference an interface such as locomotion in C++
// we need to use a pointer. We are not savages, so we use a smart pointer.

class SeaCreature {
private:
    std::unique_ptr<Locomotion> locomotion;
    std::vector<Action> actions;
    std::vector<Resource> contained_resources;
public:
    void move();

    void act();

    void collect_resources();
};