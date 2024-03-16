
const double earthRadius = 6378000.0; // Radius of the Earth in meters


double getAltitude(const Position& posElement)
{
// Note that the earth is at (0,0) whith is the default Position
double distance = computeDistance(Position(), posElement);
return distance - earthRadius;
}
