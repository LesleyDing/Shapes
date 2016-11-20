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

#include "iShapes.h"

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
  vector<string> ShapesType; // its companion array

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
          const Square* const sq = new const Square(tokens);
          Shapes.push_back(sq);
          ShapesType.push_back("SQ");
        }

        else if (tokens[0] == "RECTANGLE")
        {
          const Rectangle* const rec = new const Rectangle(tokens);
          Shapes.push_back(rec);
          ShapesType.push_back("REC");
        }

        else if (tokens[0] == "CIRCLE")
        {
          const Circle* const cir = new const Circle(tokens);
          Shapes.push_back(cir);
          ShapesType.push_back("CIR");
        }

        else if (tokens[0] == "TRIANGLE")
        {
          const Triangle* const tri = new const Triangle(tokens);
          Shapes.push_back(tri);
          ShapesType.push_back("TRI");
        }

        else if (tokens[0] == "CUBE")
        {
          const Cube* const cube = new const Cube(tokens);
          Shapes.push_back(cube);
          ShapesType.push_back("CUBE");
        }

        else if (tokens[0] == "BOX")
        {
          const Box* const box = new const Box(tokens);
          Shapes.push_back(box);
          ShapesType.push_back("BOX");
        }

        else if (tokens[0] == "CYLINDER")
        {
          const Cylinder* const cyl= new const Cylinder(tokens);
          Shapes.push_back(cyl);
          ShapesType.push_back("CYL");
        }

        else if (tokens[0] == "PRISM")
        {
          const Prism* const pri = new const Prism(tokens);
          Shapes.push_back(pri);
          ShapesType.push_back("PRI");
        }
        else
          cout << tokens[0] << " invalid object" << endl;
      }
    }
  }
  fin.close();

  // for loop of console output
  for (int i = 0; i < Shapes.size(); i++)
  {
    if (ShapesType[i] == "SQ") 
    {
      const Square* const pSquare = reinterpret_cast<const Square*>(Shapes[i]); // restore it
      const Square& rSquare = *pSquare; // dereferencing the pointer to match the function's parameter
      rSquare.output(cout);
    }
    else if (ShapesType[i] == "REC")
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(Shapes[i]); // restore it
      const Rectangle& rRectangle = *pRectangle;
      rRectangle.output(cout);
    }
    else if (ShapesType[i] == "CIR") 
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(Shapes[i]); // restore it
      const Circle& rCircle = *pCircle;
      rCircle.output(cout);
    }
    else if (ShapesType[i] == "TRI") 
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(Shapes[i]); // restore it
      const Triangle& rTriangle = *pTriangle;
      rTriangle.output(cout);
    }
    else if (ShapesType[i] == "CUBE") 
    {
      const Cube* const pCube = reinterpret_cast<const Cube*>(Shapes[i]); // restore it
      const Cube& rCube = *pCube;
      rCube.output(cout);
    }
    else if (ShapesType[i] == "BOX") 
    {
      const Box* const pBox = reinterpret_cast<const Box*>(Shapes[i]); // restore it
      const Box& rBox = *pBox;
      rBox.output(cout);
    }
    else if (ShapesType[i] == "CYL") 
    {
      const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(Shapes[i]); // restore it
      const Cylinder& rCylinder = *pCylinder;
      rCylinder.output(cout);
    }
    else if (ShapesType[i] == "PRI") 
    {
      const Prism* const pPrism = reinterpret_cast<const Prism*>(Shapes[i]); // restore it
      const Prism& rPrism = *pPrism;
      rPrism.output(cout);
    }
    else continue;
  }

  ofstream fout;
  fout.open("Shapes.output.txt"); // open a file for output

  // for loop of file output
  for (int i = 0; i < Shapes.size(); i++)
  {
    if (ShapesType[i] == "SQ") 
    {
      const Square* const pSquare = reinterpret_cast<const Square*>(Shapes[i]); // restore it
      const Square& rSquare = *pSquare; // dereferencing the pointer to match the function's parameter
      rSquare.output(fout);
    }
    else if (ShapesType[i] == "REC")
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(Shapes[i]); // restore it
      const Rectangle& rRectangle = *pRectangle;
      rRectangle.output(fout);
    }
    else if (ShapesType[i] == "CIR") 
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(Shapes[i]); // restore it
      const Circle& rCircle = *pCircle;
      rCircle.output(fout);
    }
    else if (ShapesType[i] == "TRI") 
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(Shapes[i]); // restore it
      const Triangle& rTriangle = *pTriangle;
      rTriangle.output(fout);
    }
    else if (ShapesType[i] == "CUBE") 
    {
      const Cube* const pCube = reinterpret_cast<const Cube*>(Shapes[i]); // restore it
      const Cube& rCube = *pCube;
      rCube.output(fout);
    }
    else if (ShapesType[i] == "BOX") 
    {
      const Box* const pBox = reinterpret_cast<const Box*>(Shapes[i]); // restore it
      const Box& rBox = *pBox;
      rBox.output(fout);
    }
    else if (ShapesType[i] == "CYL") 
    {
      const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(Shapes[i]); // restore it
      const Cylinder& rCylinder = *pCylinder;
      rCylinder.output(fout);
    }
    else if (ShapesType[i] == "PRI") 
    {
      const Prism* const pPrism = reinterpret_cast<const Prism*>(Shapes[i]); // restore it
      const Prism& rPrism = *pPrism;
      rPrism.output(fout);
    }
    else continue;
  }

  fout.close();

  // for loop of deallocation
  for (int i = 0; i < Shapes.size(); i++)
  {
    if (ShapesType[i] == "SQ") 
    {
      const Square* const pSquare = reinterpret_cast<const Square*>(Shapes[i]); // restore it
      delete pSquare;
    }
    else if (ShapesType[i] == "REC")
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(Shapes[i]); // restore it
      delete pRectangle;
    }
    else if (ShapesType[i] == "CIR") 
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(Shapes[i]); // restore it
      delete pCircle;
    }
    else if (ShapesType[i] == "TRI") 
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(Shapes[i]); // restore it
      delete pTriangle;
    }
    else if (ShapesType[i] == "CUBE") 
    {
      const Cube* const pCube = reinterpret_cast<const Cube*>(Shapes[i]); // restore it
      delete pCube;
    }
    else if (ShapesType[i] == "BOX") 
    {
      const Box* const pBox = reinterpret_cast<const Box*>(Shapes[i]); // restore it
      delete pBox;
    }
    else if (ShapesType[i] == "CYL") 
    {
      const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(Shapes[i]); // restore it
      delete pCylinder;
    }
    else if (ShapesType[i] == "PRI") 
    {
      const Prism* const pPrism = reinterpret_cast<const Prism*>(Shapes[i]); // restore it
      delete pPrism;
    }
    else continue;
  }
}

// text parsing function
vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}