//
// Created by marco on 17/03/2024.
//

#include <valarray>
#include "World.hpp"


namespace raycaster {

    World::World(const bool map[], int xSize, int ySize) {
        m_Map = std::make_unique<bool[]>(xSize * ySize);
        m_XSize = xSize;
        m_YSize = ySize;

        for (int i = 0; i < xSize * ySize; ++i) {
            m_Map[i] = map[i];
        }

    }

    bool World::IsWall(int x, int y) {
        return m_Map[y * m_XSize + x];

    }

    double World::RayTrace(Vector2 from, double angle) {
        bool hitWall = false;
        double rayDistance = 0;
        double eyeX = cos(angle);
        double eyeY = sin(angle);

        // find out when the ray angle intersects
        int testX, testY;

        // Start the ray casting loop
        while (!hitWall){
            rayDistance += RAY_STEP * sqrt(eyeX*eyeX + eyeY*eyeY);
            // create a plane of the player that the rays get casted out of
            testX = (int)(RAY_STEP + eyeX*rayDistance);
            testY = (int)(RAY_STEP + eyeY*rayDistance);
            // We multiply by ry distance ot increase the distance that it has travelled
            if (testX < 0 || testX > m_XSize || testY > m_YSize || testY < 0){
                hitWall = true;
                rayDistance = 20.0;
            } else {
                if (IsWall(testX, testY)){
                    hitWall = true;
                }
            }
        }

        return rayDistance;
    }




} // raycaster