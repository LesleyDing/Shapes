//Programmer name: Hanzhi Ding
//Programmer"s ID: 1466750

// c++ libraries
#include <iostream> 
#include <fstream> 
#include <vector> 
#include <iterator> 
#include <string> 
#include <sstream> 
using namespace std;

// c libraries
#include <cstdlib> // atof
#include <cmath> // sqrt

#include "pShapes.h"

vector<string> parseString(string); // text parsing function

int main()
{
  // programmer"s identification
  cout << "Programmer: Hanzhi Ding\n";
  cout << "Programmer's ID: 1466750\n";
  cout << "File: " << __FILE__ << endl;

  // create a file-reading object
  ifstream fin;
  fin.open("Shapes.input.txt"); // open the input file

  // create a bag called Shapes
  vector<const Shape*> Shapes;// an empty bag

  if (fin.good()) // check if the input can be open
  {
    // while loop for processing the input file and fill the bag
    while (!fin.eof())
    {
      string input;
      getline(fin,input);
      vector<string>tokens = parseString(input); // parse the text to string

      if (tokens.size() != 0 && tokens[0] != "EOF") // skip over the blank and the end line of the file
      {
        if (tokens[0] == "SQUARE")
        {
          const Shape* const sq = new const Square(tokens);
          Shapes.push_back(sq);
        }

        else if (tokens[0] == "RECTANGLE")
        {
          const Shape* const rec = new const Rectangle(tokens);
          Shapes.push_back(rec);
        }

        else if (tokens[0] == "CIRCLE")
        {
          const Shape* const cir = new const Circle(tokens);
          Shapes.push_back(cir);
        }

        else if (tokens[0] == "TRIANGLE")
        {
          const Shape* const tri = new const Triangle(tokens);
          Shapes.push_back(tri);
        }

        else if (tokens[0] == "CUBE")
        {
          const Shape* const cube = new const Cube(tokens);
          Shapes.push_back(cube);
        }

        else if (tokens[0] == "BOX")
        {
          const Shape* const box = new const Box(tokens);
          Shapes.push_back(box);
        }

        else if (tokens[0] == "CYLINDER")
        {
          const Shape* const cyl= new const Cylinder(tokens);
          Shapes.push_back(cyl);
        }

        else if (tokens[0] == "PRISM")
        {
          const Shape* const pri = new const Prism(tokens);
          Shapes.push_back(pri);
        }
        else
          cout << tokens[0] << " invalid object" << endl;
      }
    }
  }
  fin.close();

  // for loop of console output
  for (unsigned int i = 0; i < Shapes.size(); i++)
    cout << Shapes[i];

  ofstream fout;
  fout.open("Shapes.output.txt"); // open a file for output

  // for loop of file output
  for (unsigned int i = 0; i < Shapes.size(); i++)
    fout << Shapes[i];

  fout.close();

  for (unsigned int i = 0; i < Shapes.size(); i++)
    delete Shapes[i];
}

// text parsing function
vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}