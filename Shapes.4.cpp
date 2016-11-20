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
class Square
{
  const double side; // constant data member 
public:
  void output(ostream&) const; //m ember function
  Square (const vector<string>&); // constructor functions 
  Square& operator=(const Square&); // parameter is a constant reference
};

class Rectangle
{
  const double length;
  const double width;
public:
  void output(ostream&) const; //member function
  Rectangle (const vector<string>&); // constructor functions
  Rectangle& operator=(const Rectangle&); // parameter is a constant reference
};

class Circle
{
  const double radius;
public:
  void output(ostream&) const; //member function
  Circle(const vector<string>&); // constructor functions
  Circle& operator=(const Circle&); // parameter is a constant reference
};

class Triangle
{
  const double side;
public:
  void output(ostream&) const; //member function
  Triangle(const vector<string>&); // constructor functions
  Triangle& operator=(const Triangle&); // parameter is a constant reference
};

class Cube
{
  const double side;
public:
  void output(ostream&) const; //member function
  Cube(const vector<string>&); // constructor functions
  Cube& operator=(const Cube&); // parameter is a constant reference
};

class Box
{
  const double length;
  const double width;
  const double height;
public:
  void output(ostream&) const; //member function
  Box(const vector<string>&); // constructor functions
  Box& operator=(const Box&); // parameter is a constant reference
};

class Cylinder
{
  const double radius;
  const double height;
public:
  void output(ostream&) const; //member function
  Cylinder(const vector<string>&); // constructor functions
  Cylinder& operator=(const Cylinder&); // parameter is a constant reference
};

class Prism
{
  const double side;
  const double height;
public:
  void output(ostream&) const; //member function
  Prism(const vector<string>&); // constructor functions
  Prism& operator=(const Prism&); // parameter is a constant reference
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
  vector<const void*> Shapes;// an empty bag
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

  // nested-for-loop sort by name
  for (int i = 0; i < Shapes.size(); i++)
    for (int j = i + 1; j < Shapes.size(); j++)
      if (ShapesType[j] < ShapesType[i])
      {
	    swap(Shapes[i], Shapes[j]);
	    swap(ShapesType[i], ShapesType[j]);
	  }

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
void Square::output(ostream& out) const
{
  out << "SQUARE side=" << side;
  out << roundingTwo << " area=" << side * side << " perimeter=" << side * 4 << roundingOff << endl;
}

Square::Square (const vector<string>& tokens)
: side (tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) // this is the initializer list
{
}

Square& Square::operator=(const Square& copyThis)
{
  Square& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
     const_cast<double&>(host.side) = copyThis.side;
  }
  return host; // returns a "self-reference"
}

void Rectangle::output(ostream& out) const
{
  out << "RECTANGLE length=" << length << " width=" << width;
  out << roundingTwo << " area=" << length * width << " perimeter=" << (length + width) * 2 << roundingOff << endl;
}

Rectangle::Rectangle(const vector<string>& tokens)
: length (tokens.size() > 1 ? atof(tokens[1].c_str()) : 0), // this is the initializer list
  width (tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) // this is the initializer list
{
}

Rectangle& Rectangle::operator=(const Rectangle& copyThis)
{
  Rectangle& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
     const_cast<double&>(host.length) = copyThis.length;
	 const_cast<double&>(host.width) = copyThis.width;
  }
  return host; // returns a "self-reference"
}

void Circle::output(ostream& out) const
{
  out << "CIRCLE radius=" << radius;
  out << roundingTwo << " area=" << radius * radius * PI << " perimeter=" << 2 * radius * PI << roundingOff << endl;
}

Circle::Circle (const vector<string>& tokens)
: radius (tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) // this is the initializer list
{
}

Circle& Circle::operator=(const Circle& copyThis)
{
  Circle& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
     const_cast<double&>(host.radius) = copyThis.radius;
  }
  return host; // returns a "self-reference"
}

void Triangle::output(ostream& out) const
{
  out << "TRIANGLE side=" << side;
  out << roundingTwo << " area=" << sqrt(3.0) * side * side / 4 << " perimeter=" << 3 * side << roundingOff << endl;
}

Triangle::Triangle (const vector<string>& tokens)
: side (tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) // this is the initializer list
{
}

Triangle& Triangle::operator=(const Triangle& copyThis)
{
  Triangle& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
     const_cast<double&>(host.side) = copyThis.side;
  }
  return host; // returns a "self-reference"
}

void Cube::output(ostream& out) const
{
  out << "CUBE side=" << side;
  out << roundingTwo << " surface area=" << side * side * 6 << " volume=" << side * side * side << roundingOff << endl;
}

Cube::Cube (const vector<string>& tokens)
: side (tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) // this is the initializer list
{
}

Cube& Cube::operator=(const Cube& copyThis)
{
  Cube& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
     const_cast<double&>(host.side) = copyThis.side;
  }
  return host; // returns a "self-reference"
}

void Box::output(ostream& out) const
{
  out << "BOX length=" << length << " width=" << width << " height=" << height;
  out << roundingTwo << " surface area=" << (length * width + length * height + width * height) * 2 << " volume=" <<  length * width * height << roundingOff << endl;
}

Box::Box (const vector<string>& tokens)
: length (tokens.size() > 1 ? atof(tokens[1].c_str()) : 0), // this is the initializer list
  width (tokens.size() > 2 ? atof(tokens[2].c_str()) : 0), // this is the initializer list
  height (tokens.size() > 3 ? atof(tokens[3].c_str()) : 0) // this is the initializer list
{
}

Box& Box::operator=(const Box& copyThis)
{
  Box& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
     const_cast<double&>(host.length) = copyThis.length;
	 const_cast<double&>(host.width) = copyThis.width;
	 const_cast<double&>(host.height) = copyThis.height;
  }
  return host; // returns a "self-reference"
}

void Cylinder::output(ostream& out) const
{
  out << "CYLINDER radius=" << radius << " height=" << height;
  out << roundingTwo << " surface area=" << 2 * radius * radius * PI + 2 * radius * PI * height << " volume=" << radius * radius * PI * height << roundingOff << endl;
}

Cylinder::Cylinder(const vector<string>& tokens)
: radius (tokens.size() > 1 ? atof(tokens[1].c_str()) : 0), // this is the initializer list
  height (tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) // this is the initializer list
{
}

Cylinder& Cylinder::operator=(const Cylinder& copyThis)
{
  Cylinder& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
     const_cast<double&>(host.radius) = copyThis.radius;
	 const_cast<double&>(host.height) = copyThis.height;
  }
  return host; // returns a "self-reference"
}

void Prism::output(ostream& out) const
{
  out << "PRISM side=" << side << " height=" << height;
  out << roundingTwo << " surface area=" << sqrt(3.0) * side * side / 4 * 2 + 3 * side * height << " volume=" << sqrt(3) * side * height << roundingOff << endl;
}

Prism::Prism(const vector<string>& tokens)
: side (tokens.size() > 1 ? atof(tokens[1].c_str()) : 0), // this is the initializer list
  height (tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) // this is the initializer list
{
}

Prism& Prism::operator=(const Prism& copyThis)
{
  Prism& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
     const_cast<double&>(host.side) = copyThis.side;
	 const_cast<double&>(host.height) = copyThis.height;
  }
  return host; // returns a "self-reference"
}
