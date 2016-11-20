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

// structs of shapes
struct Square
{
  double side;
  void outputSquare(ostream&) const; //member function
};

struct Rectangle
{
  double length;
  double width;
  void outputRectangle(ostream&) const; //member function
};

struct Circle
{
  double radius;
  void outputCircle(ostream&) const; //member function
};

struct Triangle
{
  double side;
  void outputTriangle(ostream&) const; //member function
};

struct Cube
{
  double side;
  void outputCube(ostream&) const; //member function
};

struct Box
{
  double length;
  double width;
  double height;
  void outputBox(ostream&) const; //member function
};

struct Cylinder
{
  double radius;
  double height;
  void outputCylinder(ostream&) const; //member function
};

struct Prism
{
  double side;
  double height;
  void outputPrism(ostream&) const; //member function
};

// prototypes
vector<string> parseString(string); // text parsing function
ostream& roundingTwo(ostream&); // a manipulator to turn on floating point rounding
ostream& roundingOff(ostream&); // a manipulator to turn off floating point rounding

const double PI = 3.14159;

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
  vector<void*> Shapes;// an empty bag
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
          Square* sq = new Square;
          sq->side = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0; // use conditional operators instead if-else statements to convert tokens to dimensions
          Shapes.push_back(sq);
          ShapesType.push_back("SQ");
	    }

	    else if (tokens[0] == "RECTANGLE")
        {
          Rectangle* rec = new Rectangle;
          rec->length = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
          rec->width = tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0;
          Shapes.push_back(rec);
		  ShapesType.push_back("REC");
	    }

	    else if (tokens[0] == "CIRCLE")
        {
          Circle* cir = new Circle;
          cir->radius = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
		  Shapes.push_back(cir);
          ShapesType.push_back("CIR");
	    }
	  
	    else if (tokens[0] == "TRIANGLE")
        {
          Triangle* tri = new Triangle;
          tri->side = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
 		  Shapes.push_back(tri);
		  ShapesType.push_back("TRI");
	    }
      
	    else if (tokens[0] == "CUBE")
        {
          Cube* cube = new Cube;
          cube->side = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
		  Shapes.push_back(cube);
		  ShapesType.push_back("CUBE");
	    }
       
		else if (tokens[0] == "BOX")
        {
          Box* box = new Box;
          box->length = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
          box->width = tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0;
          box->height = tokens.size() >= 4 ? atof(tokens[3].c_str()) : 0;
		  Shapes.push_back(box);
	  	  ShapesType.push_back("BOX");
        }
		
	    else if (tokens[0] == "CYLINDER")
        {
          Cylinder* cyl= new Cylinder;
          cyl->radius = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
          cyl->height = tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0;
          Shapes.push_back(cyl);
          ShapesType.push_back("CYL");
        }
        
	    else if (tokens[0] == "PRISM")
        {
          Prism* pri = new Prism;
          pri->side = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;;
          pri->height = tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0;;
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
  for (int i = 0; i < Shapes.size( ); i++)
  {
    if (ShapesType[i] == "SQ") 
	{
      Square* pSquare = reinterpret_cast<Square*>(Shapes[i]); // restore it
      Square& rSquare = *pSquare; // dereferencing the pointer to match the function's parameter
      rSquare.outputSquare(cout);
    }
    else if (ShapesType[i] == "REC")
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(Shapes[i]); // restore it
      Rectangle& rRectangle = *pRectangle;
      rRectangle.outputRectangle(cout);
    }
    else if (ShapesType[i] == "CIR") 
    {
      Circle* pCircle = reinterpret_cast<Circle*>(Shapes[i]); // restore it
      Circle& rCircle = *pCircle;
      rCircle.outputCircle(cout);
    }
    else if (ShapesType[i] == "TRI") 
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(Shapes[i]); // restore it
      Triangle& rTriangle = *pTriangle;
      rTriangle.outputTriangle(cout);
    }
    else if (ShapesType[i] == "CUBE") 
    {
      Cube* pCube = reinterpret_cast<Cube*>(Shapes[i]); // restore it
      Cube& rCube = *pCube;
      rCube.outputCube(cout);
    }
    else if (ShapesType[i] == "BOX") 
    {
      Box* pBox = reinterpret_cast<Box*>(Shapes[i]); // restore it
      Box& rBox = *pBox;
      rBox.outputBox(cout);
    }
    else if (ShapesType[i] == "CYL") 
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(Shapes[i]); // restore it
      Cylinder& rCylinder = *pCylinder;
      rCylinder.outputCylinder(cout);
    }
    else if (ShapesType[i] == "PRI") 
    {
      Prism* pPrism = reinterpret_cast<Prism*>(Shapes[i]); // restore it
      Prism& rPrism = *pPrism;
      rPrism.outputPrism(cout);
    }
    else continue;
  }

  ofstream fout;
  fout.open("Shapes.output.txt"); // open a file for output

  // for loop of file output
  for (int i = 0; i < Shapes.size( ); i++)
  {
    if (ShapesType[i] == "SQ") 
	{
      Square* pSquare = reinterpret_cast<Square*>(Shapes[i]); // restore it
      Square& rSquare = *pSquare; // dereferencing the pointer to match the function's parameter
      rSquare.outputSquare(fout);
    }
    else if (ShapesType[i] == "REC")
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(Shapes[i]); // restore it
      Rectangle& rRectangle = *pRectangle;
      rRectangle.outputRectangle(fout);
    }
    else if (ShapesType[i] == "CIR") 
    {
      Circle* pCircle = reinterpret_cast<Circle*>(Shapes[i]); // restore it
      Circle& rCircle = *pCircle;
      rCircle.outputCircle(fout);
    }
    else if (ShapesType[i] == "TRI") 
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(Shapes[i]); // restore it
      Triangle& rTriangle = *pTriangle;
      rTriangle.outputTriangle(fout);
    }
    else if (ShapesType[i] == "CUBE") 
    {
      Cube* pCube = reinterpret_cast<Cube*>(Shapes[i]); // restore it
      Cube& rCube = *pCube;
      rCube.outputCube(fout);
    }
    else if (ShapesType[i] == "BOX") 
    {
      Box* pBox = reinterpret_cast<Box*>(Shapes[i]); // restore it
      Box& rBox = *pBox;
      rBox.outputBox(fout);
    }
    else if (ShapesType[i] == "CYL") 
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(Shapes[i]); // restore it
      Cylinder& rCylinder = *pCylinder;
      rCylinder.outputCylinder(fout);
    }
    else if (ShapesType[i] == "PRI") 
    {
      Prism* pPrism = reinterpret_cast<Prism*>(Shapes[i]); // restore it
      Prism& rPrism = *pPrism;
      rPrism.outputPrism(fout);
    }
    else continue;
  }

  // for loop of deallocation
  for (int i = 0; i < Shapes.size( ); i++)
  {
    if (ShapesType[i] == "SQ") 
    {
      Square* pSquare = reinterpret_cast<Square*>(Shapes[i]); // restore it
      delete pSquare;
    }
    else if (ShapesType[i] == "REC")
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(Shapes[i]); // restore it
      delete pRectangle;
    }
    else if (ShapesType[i] == "CIR") 
    {
      Circle* pCircle = reinterpret_cast<Circle*>(Shapes[i]); // restore it
      delete pCircle;
    }
    else if (ShapesType[i] == "TRI") 
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(Shapes[i]); // restore it
      delete pTriangle;
    }
    else if (ShapesType[i] == "CUBE") 
    {
      Cube* pCube = reinterpret_cast<Cube*>(Shapes[i]); // restore it
      delete pCube;
    }
    else if (ShapesType[i] == "BOX") 
    {
      Box* pBox = reinterpret_cast<Box*>(Shapes[i]); // restore it
      delete pBox;
    }
    else if (ShapesType[i] == "CYL") 
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(Shapes[i]); // restore it
      delete pCylinder;
    }
    else if (ShapesType[i] == "PRI") 
    {
      Prism* pPrism = reinterpret_cast<Prism*>(Shapes[i]); // restore it
      delete pPrism;
    }
    else continue;
  }
  fout.close();
}

// text parsing function
vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}

// a manipulator to turn on floating point rounding
ostream& roundingTwo(ostream& out)
{
  out.setf(ios::fixed);
  out.precision(2); // 2 decimal digits
  return out;
}

// a manipulator to turn off floating point rounding
ostream& roundingOff(ostream& out)
{
  out.unsetf(ios::fixed);
  out.precision(6); // the C++ default
  return out;
}

// member functions of the structs
void Square::outputSquare(ostream& out) const
{
  out << "SQUARE side=" << side;
  out << roundingTwo << " area=" << side * side << " perimeter=" << side * 4 << roundingOff << endl;
}

void Rectangle::outputRectangle(ostream& out) const
{
  out << "RECTANGLE length=" << length << " width=" << width;
  out << roundingTwo << " area=" << length * width << " perimeter=" << (length + width) * 2 << roundingOff << endl;
}

void Circle::outputCircle(ostream& out) const
{
  out << "CIRCLE radius=" << radius;
  out << roundingTwo << " area=" << radius * radius * PI << " perimeter=" << 2 * radius * PI << roundingOff << endl;
}

void Triangle::outputTriangle(ostream& out) const
{
  out << "TRIANGLE side=" << side;
  out << roundingTwo << " area=" << sqrt(3) * side * side / 4 << " perimeter=" << 3 * side << roundingOff << endl;
}

void Cube::outputCube(ostream& out) const
{
  out << "CUBE side=" << side;
  out << roundingTwo << " surface area=" << side * side * 6 << " volume=" << side * side * side << roundingOff << endl;
}

void Box::outputBox(ostream& out) const
{
  out << "BOX length=" << length << " width=" << width << " height=" << height;
  out << roundingTwo << " surface area=" << (length * width + length * height + width * height) * 2 << " volume=" <<  length * width * height << roundingOff << endl;
}

void Cylinder::outputCylinder(ostream& out) const
{
  out << "CYLINDER radius=" << radius << " height=" << height;
  out << roundingTwo << " surface area=" << 2 * radius * radius * PI + 2 * radius * PI * height << " volume=" << radius * radius * PI * height << roundingOff << endl;
}

void Prism::outputPrism(ostream& out) const
{
  out << "PRISM side=" << side << " height=" << height;
  out << roundingTwo << " surface area=" << sqrt(3) * side * side / 4 * 2 + 3 * side * height << " volume=" << sqrt(3) * side * height << roundingOff << endl;
}
