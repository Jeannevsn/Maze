#include <Arduino.h>
#include <stdio.h>
#include <inttypes.h>
#include "maze.h"

using namespace std;

bool Maze::position_check(int x, int y) const
{
    // conditions for not leaving the matrix
    if (x < 0 || y < 0)
        return false;
    else
    {
        if (x > WIDTH_MAZE - 1 || y > 7)
            return false;
        else
            return true;
    }
}

bool Maze::left_path_check(int x, int y) const
{
    if ((position_check(x - 1, y) == true) && (m_maze[m_index_maze][y][x][0] == 0))
        return true;
    else
        return false;
}

bool Maze::right_path_check(int x, int y) const
{
    if ((position_check(x + 1, y) == true) && (m_maze[m_index_maze][y][x + 1][0] == 0))
        return true;
    else
        return false;
}

bool Maze::bottom_path_check(int x, int y) const
{
    if ((position_check(x, y + 1) == true) && (m_maze[m_index_maze][y][x][1] == 0))
        return true;
    else
        return false;
}

bool Maze::top_path_check(int x, int y) const
{

    if ((position_check(x, y - 1) == true) && (m_maze[m_index_maze][y - 1][x][1] == 0))
        return true;
    else
        return false;
}

void Maze::print_state(void) const
{
    Serial.printf("Numero maze : %d \n", m_index_maze);

}

Maze::Maze():
    m_maze {
        {// Row 0
         {{0, 0}, {0, 0}, {1, 0}, {0, 1}, {0, 0}, {1, 0}, {0, 1}, {0, 0}},
         // Row 1
         {{0, 0}, {1, 1}, {0, 1}, {1, 0}, {1, 0}, {0, 0}, {1, 1}, {0, 1}},
         // Row 2
         {{0, 1}, {0, 0}, {0, 0}, {1, 0}, {0, 1}, {1, 1}, {0, 1}, {0, 0}},
         // Row 3
         {{0, 0}, {1, 0}, {1, 0}, {1, 1}, {1, 0}, {0, 1}, {0, 1}, {1, 0}},
         // Row 4
         {{0, 0}, {0, 1}, {1, 1}, {0, 0}, {1, 1}, {0, 0}, {1, 0}, {0, 1}},
         // Row 5
         {{0, 0}, {1, 1}, {0, 0}, {0, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 0}},
         // Row 6
         {{0, 0}, {1, 0}, {0, 1}, {1, 0}, {0, 0}, {1, 0}, {0, 1}, {1, 0}},
         // Row 7
         {{0, 0}, {1, 0}, {0, 0}, {0, 0}, {1, 0}, {1, 0}, {0, 0}, {0, 0}}},

        {// Row 0
         {{0, 0}, {0, 1}, {1, 0}, {0, 0}, {0, 0}, {0, 1}, {0, 0}, {1, 0}},
         // Row 1
         {{0, 0}, {0, 0}, {1, 0}, {1, 1}, {1, 0}, {0, 1}, {1, 0}, {0, 0}},
         // Row 2
         {{0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 1}, {1, 0}, {0, 1}, {1, 0}},
         // Row 3
         {{0, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 0}},
         // Row 4
         {{0, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 1}, {0, 0}, {1, 1}, {0, 1}},
         // Row 5
         {{0, 0}, {1, 1}, {0, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {0, 0}},
         // Row 6
         {{0, 0}, {1, 0}, {1, 0}, {0, 1}, {1, 0}, {1, 0}, {1, 0}, {0, 0}},
         // Row 7
         {{0, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}}},

        {// Row 0
         {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}},
         // Row 1
         {{0, 1}, {1, 0}, {1, 0}, {1, 1}, {1, 0}, {0, 0}, {1, 1}, {0, 1}},
         // Row 2
         {{0, 0}, {0, 1}, {1, 1}, {0, 0}, {1, 0}, {1, 1}, {0, 1}, {0, 0}},
         // Row 3
         {{0, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 0}, {0, 0}, {1, 1}, {0, 1}},
         // Row 4
         {{0, 0}, {1, 1}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}},
         // Row 5
         {{0, 1}, {1, 0}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {1, 1}, {0, 0}},
         // Row 6
         {{0, 0}, {1, 1}, {0, 0}, {1, 0}, {1, 1}, {0, 1}, {0, 0}, {1, 0}},
         // Row 7
         {{0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}}},

        {// Row 0
         {{0, 0}, {0, 1}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 1}, {0, 0}},
         // Row 1
         {{0, 1}, {0, 0}, {1, 1}, {0, 1}, {1, 1}, {0, 0}, {1, 0}, {0, 1}},
         // Row 2
         {{0, 0}, {0, 1}, {1, 0}, {0, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}},
         // Row 3
         {{0, 0}, {1, 0}, {0, 1}, {1, 1}, {1, 1}, {0, 1}, {1, 1}, {0, 0}},
         // Row 4
         {{0, 0}, {1, 1}, {0, 1}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {1, 0}},
         // Row 5
         {{0, 1}, {0, 1}, {0, 1}, {1, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}},
         // Row 6
         {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 1}, {1, 1}, {0, 0}},
         // Row 7
         {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}},

        {// Row 0
         {{0, 0}, {0, 1}, {0, 1}, {0, 1}, {0, 0}, {0, 0}, {0, 1}, {0, 0}},
         // Row 1
         {{0, 0}, {1, 1}, {0, 1}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 1}},
         // Row 2
         {{0, 1}, {0, 0}, {0, 1}, {1, 1}, {0, 1}, {1, 0}, {1, 1}, {0, 0}},
         // Row 3
         {{0, 0}, {0, 1}, {0, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}},
         // Row 4
         {{0, 1}, {0, 1}, {1, 0}, {0, 0}, {1, 1}, {0, 0}, {0, 0}, {1, 0}},
         // Row 5
         {{0, 0}, {0, 0}, {1, 0}, {1, 1}, {0, 0}, {1, 0}, {1, 1}, {1, 0}},
         // Row 6
         {{0, 0}, {1, 1}, {1, 1}, {0, 0}, {1, 1}, {1, 1}, {0, 0}, {1, 0}},
         // Row 7
         {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}}},

        {// Row 0
         {{0, 0}, {0, 1}, {0, 0}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 0}},
         // Row 1
         {{0, 1}, {0, 1}, {1, 0}, {0, 1}, {0, 1}, {0, 0}, {1, 1}, {0, 1}},
         // Row 2
         {{0, 0}, {0, 0}, {1, 1}, {0, 1}, {0, 0}, {1, 1}, {0, 1}, {0, 0}},
         // Row 3
         {{0, 0}, {1, 1}, {0, 0}, {1, 0}, {0, 1}, {1, 1}, {0, 0}, {1, 0}},
         // Row 4
         {{0, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {0, 1}, {0, 1}, {1, 0}},
         // Row 5
         {{0, 1}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {0, 1}, {0, 1}},
         // Row 6
         {{0, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 1}, {0, 0}},
         // Row 7
         {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {0, 0}}},

        {// Row 0
         {{0, 0}, {0, 0}, {0, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 1}, {0, 0}},
         // Row 1
         {{0, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 1}},
         // Row 2
         {{0, 0}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 0}, {1, 1}, {0, 0}},
         // Row 3
         {{0, 1}, {1, 0}, {1, 1}, {0, 0}, {1, 0}, {0, 1}, {1, 0}, {1, 0}},
         // Row 4
         {{0, 0}, {0, 0}, {1, 1}, {0, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 0}},
         // Row 5
         {{0, 0}, {1, 1}, {1, 0}, {0, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}},
         // Row 6
         {{0, 0}, {1, 0}, {0, 1}, {1, 1}, {0, 1}, {1, 0}, {0, 0}, {1, 0}},
         // Row 7
         {{0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}}},

        {// Row 0
         {{0, 0}, {0, 1}, {0, 0}, {0, 1}, {0, 0}, {1, 1}, {0, 0}, {0, 0}},
         // Row 1
         {{0, 0}, {0, 0}, {1, 1}, {0, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 1}},
         // Row 2
         {{0, 0}, {1, 1}, {0, 0}, {1, 0}, {0, 1}, {0, 1}, {0, 1}, {0, 0}},
         // Row 3
         {{0, 1}, {1, 0}, {0, 1}, {1, 0}, {1, 0}, {0, 1}, {1, 0}, {0, 1}},
         // Row 4
         {{0, 0}, {0, 1}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 1}},
         // Row 5
         {{0, 1}, {0, 0}, {1, 0}, {1, 0}, {1, 1}, {1, 0}, {1, 1}, {0, 0}},
         // Row 6
         {{0, 0}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {0, 1}, {1, 0}, {0, 1}},
         // Row 7
         {{0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}}},

        {// Row 0
         {{0, 0}, {0, 1}, {0, 0}, {1, 1}, {0, 0}, {0, 0}, {0, 0}, {1, 0}},
         // Row 1
         {{0, 0}, {1, 1}, {0, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 0}},
         // Row 2
         {{0, 1}, {0, 0}, {1, 1}, {0, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}},
         // Row 3
         {{0, 0}, {0, 1}, {0, 1}, {1, 1}, {0, 1}, {0, 0}, {1, 0}, {1, 0}},
         // Row 4
         {{0, 1}, {0, 0}, {1, 0}, {0, 1}, {0, 1}, {0, 1}, {1, 0}, {0, 1}},
         // Row 5
         {{0, 0}, {0, 1}, {1, 1}, {0, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 0}},
         // Row 6
         {{0, 0}, {0, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {0, 1}, {1, 0}},
         // Row 7
         {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}}}}
         
         {
    randomize_maze();
}

void Maze::randomize_maze()
{
    m_index_maze = random(0, 9);

    for (int i = 0; i < 2; i++)
    {
        m_start[i] = random(0, 8);
        m_finish[i] = random(0, 8);
    }
}

bool Maze::is_finished(int x, int y) const
{
    if (x == m_finish[0] && y == m_finish[1])
        return true;
    else
        return false;
}

void Maze::get_start_position(int &x, int &y)
{
    x = m_start[0];
    y = m_start[1];
}
void Maze::get_finish_position(int &x, int &y)
{
    x = m_finish[0];
    y = m_finish[1];
}