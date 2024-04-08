
#include "hubble.h"

Hubble::Hubble() {
    pos.setMeters(0.0, 42164000.0);
    velocity.setDxDy(-3100.0, 0.0);
    direction = velocity.getDirection();
    angularVelocity = -0.02;
    radius = 12 * pos.getZoom();
}

void Hubble::draw() const {
    ogstream().drawHubble(pos, direction.getRadians());
}

void Hubble::destroy(std::vector<Satellite*>* satellites) {

    satellites->push_back(new HubbleLeft(this->getPosition(), Direction(90)));
    satellites->push_back(new HubbleRight(this->getPosition(), Direction(180)));
    satellites->push_back(new HubbleComputer(this->getPosition(), Direction(270)));
    satellites->push_back(new HubbleTelescope(this->getPosition(), Direction(0)));

    kill();
}
