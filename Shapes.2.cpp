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
};

struct Rectangle
{
  double length;
  double width;
};

struct Circle
{
  double radius;
};

struct Triangle
{
  double side;
};

struct Cube
{
  double side;
};

struct Box
{
  double length;
  double width;
  double height;
};

struct Cylinder
{
  double radius;
  double height;
};

struct Prism
{
  double side;
  double height;
};

// supporting functions"s prototypes
void outputSquare(ostream&, const Square&);
void outputRectangle(ostream&, const Rectangle&);
void outputCircle(ostream&, const Circle&);
void outputTriangle(ostream&, const Triangle&);
void outputCube(ostream&, const Cube&);
void outputBox(ostream&, const Box&);
void outputCylinder(ostream&, const Cylinder&);
void outputPrism(ostream&, const Prism&);

// prototypes
vector<string> parseString(string);

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
	  	  if (tokens.size() >= 2)
		    sq->side = atof(tokens[1].c_str());
		  else 
		    sq->side = 0;
	      Shapes.push_back(sq);
		  ShapesType.push_back("SQ");
	    }

	    else if (tokens[0] == "RECTANGLE")
        {
          Rectangle* rec = new Rectangle;
		  if (tokens.size() >= 3)
		  {	
	  	    rec->length = atof(tokens[1].c_str());
	  	    rec->width = atof(tokens[2].c_str());
		  }
	      else if (tokens.size() == 2)
	      {	
		    rec->length = atof(tokens[1].c_str());
		    rec->width = 0;
		  }
		  else
		  {	
		    rec->length = 0;
		    rec->width = 0;
		  }
		  Shapes.push_back(rec);
		  ShapesType.push_back("REC");
	    }

	    else if (tokens[0] == "CIRCLE")
        {
          Circle* cir = new Circle;
		  if (tokens.size() >= 2)  
		    cir->radius = atof(tokens[1].c_str());
	  	  else
		    cir->radius = 0;
		  Shapes.push_back(cir);
          ShapesType.push_back("CIR");
	    }
	  
	    else if (tokens[0] == "TRIANGLE")
        {
          Triangle* tri = new Triangle;
		  if (tokens.size() >= 2)
		    tri->side = atof(tokens[1].c_str());
		  else 
		    tri->side = 0;
		  Shapes.push_back(tri);
		  ShapesType.push_back("TRI");
	    }
      
	    else if (tokens[0] == "CUBE")
        {
          Cube* cube = new Cube;
	  	  if (tokens.size() >= 2)
		    cube->side = atof(tokens[1].c_str());
		  else 
		    cube->side = 0;
		  Shapes.push_back(cube);
		  ShapesType.push_back("CUBE");
	    }
       
		else if (tokens[0] == "BOX")
        {
          Box* box = new Box;
          if (tokens.size() >= 4)
          {	
            box->length = atof(tokens[1].c_str());
		    box->width = atof(tokens[2].c_str());
	        box->height = atof(tokens[3].c_str());
          }
          else if (tokens.size() == 3)
          {	
            box->length = atof(tokens[1].c_str());
            box->width = atof(tokens[2].c_str());
            box->height = 0;
          }
          else if (tokens.size() == 2)
          {	
            box->length = atof(tokens[1].c_str());
            box->width = 0;
            box->height = 0;
          }
          else
          {	
		    box->length = 0;
		    box->width = 0;
		    box->height = 0;
          }
		  Shapes.push_back(box);
	  	  ShapesType.push_back("BOX");
        }
		
	    else if (tokens[0] == "CYLINDER")
        {
          Cylinder* cyl= new Cylinder;
          if (tokens.size() >= 3)
          {	
            cyl->radius = atof(tokens[1].c_str());
            cyl->height = atof(tokens[2].c_str());
          }
          else if (tokens.size() == 2)
          {	
            cyl->radius = atof(tokens[1].c_str());
            cyl->height = 0;
          }
          else
          {	
            cyl->radius = 0;
            cyl->height = 0;
          }
          Shapes.push_back(cyl);
          ShapesType.push_back("CYL");
        }
        
	    else if (tokens[0] == "PRISM")
        {
          Prism* pri = new Prism;
          if (tokens.size() >= 3)
          {	
            pri->side = atof(tokens[1].c_str());
            pri->height = atof(tokens[2].c_str());
          }
          else if (tokens.size() == 2)
          {	
            pri->side = atof(tokens[1].c_str());
            pri->height = 0;
          }
          else
          {	
            pri->side = 0;
            pri->height = 0;
          }
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
      outputSquare(cout, rSquare);
    }
    else if (ShapesType[i] == "REC")
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(Shapes[i]); // restore it
      Rectangle& rRectangle = *pRectangle;
      outputRectangle(cout, rRectangle);
    }
    else if (ShapesType[i] == "CIR") 
    {
      Circle* pCircle = reinterpret_cast<Circle*>(Shapes[i]); // restore it
      Circle& rCircle = *pCircle;
      outputCircle(cout, rCircle);
    }
    else if (ShapesType[i] == "TRI") 
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(Shapes[i]); // restore it
      Triangle& rTriangle = *pTriangle;
      outputTriangle(cout, rTriangle);
    }
    else if (ShapesType[i] == "CUBE") 
    {
      Cube* pCube = reinterpret_cast<Cube*>(Shapes[i]); // restore it
      Cube& rCube = *pCube;
      outputCube(cout, rCube);
    }
    else if (ShapesType[i] == "BOX") 
    {
      Box* pBox = reinterpret_cast<Box*>(Shapes[i]); // restore it
      Box& rBox = *pBox;
      outputBox(cout, rBox);
    }
    else if (ShapesType[i] == "CYL") 
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(Shapes[i]); // restore it
      Cylinder& rCylinder = *pCylinder;
      outputCylinder(cout, rCylinder);
    }
    else if (ShapesType[i] == "PRI") 
    {
      Prism* pPrism = reinterpret_cast<Prism*>(Shapes[i]); // restore it
      Prism& rPrism = *pPrism;
      outputPrism(cout, rPrism);
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
	  Square& rSquare = *pSquare;
      outputSquare(fout, rSquare);
    }
    else if (ShapesType[i] == "REC")
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(Shapes[i]); // restore it
      Rectangle& rRectangle = *pRectangle;
      outputRectangle(fout, rRectangle);
    }
    else if (ShapesType[i] == "CIR") 
    {
      Circle* pCircle = reinterpret_cast<Circle*>(Shapes[i]); // restore it
      Circle& rCircle = *pCircle;
      outputCircle(fout, rCircle);
    }
    else if (ShapesType[i] == "TRI") 
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(Shapes[i]); // restore it
      Triangle& rTriangle = *pTriangle;
      outputTriangle(fout, rTriangle);
    }
    else if (ShapesType[i] == "CUBE") 
    {
      Cube* pCube = reinterpret_cast<Cube*>(Shapes[i]); // restore it
      Cube& rCube = *pCube;
      outputCube(fout, rCube);
    }
    else if (ShapesType[i] == "BOX") 
    {
      Box* pBox = reinterpret_cast<Box*>(Shapes[i]); // restore it
      Box& rBox = *pBox;
      outputBox(fout, rBox);
    }
    else if (ShapesType[i] == "CYL") 
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(Shapes[i]); // restore it
      Cylinder& rCylinder = *pCylinder;
      outputCylinder(fout, rCylinder);
    }
    else if (ShapesType[i] == "PRI") 
    {
      Prism* pPrism = reinterpret_cast<Prism*>(Shapes[i]); // restore it
      Prism& rPrism = *pPrism;
      outputPrism(fout, rPrism);
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

// parseString function
vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}

void outputSquare(ostream& out, const Square& x)
{
  out << "SQUARE side=" << x.side;
  out.setf(ios::fixed);
  out.precision(2);
  out << " area=" << x.side * x.side << " perimeter=" << x.side * 4 << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}

void outputRectangle(ostream& out, const Rectangle& x)
{
  out << "RECTANGLE length=" << x.length << " width=" << x.width;
  out.setf(ios::fixed);
  out.precision(2);
  out << " area=" << x.length * x.width << " perimeter=" << (x.length + x.width) * 2 << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}

void outputCircle(ostream& out, const Circle& x)
{
  const double PI = 3.14159;
  out << "CIRCLE radius=" << x.radius;
  out.setf(ios::fixed);
  out.precision(2);
  out << " area=" << x.radius * x.radius * PI << " perimeter=" << 2 * x.radius * PI << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}

void outputTriangle(ostream& out, const Triangle& x)
{
  out << "TRIANGLE side=" << x.side;
  out.setf(ios::fixed);
  out.precision(2);
  out << " area=" << sqrt(3) * x.side * x.side / 4 << " perimeter=" << 3 * x.side << endl;
  out.unsetf(ios::fixed);
 out.precision(6);
}

void outputCube(ostream& out, const Cube& x)
{
  out << "CUBE side=" << x.side;
  out.setf(ios::fixed);
  out.precision(2);
  out << " surface area=" << x.side * x.side * 6 << " volume=" << x.side * x.side * x.side << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}

void outputBox(ostream& out, const Box& x)
{
  out << "BOX length=" << x.length << " width=" << x.width << " height=" << x.height;
  out.setf(ios::fixed);
  out.precision(2);
  out << " surface area=" << (x.length * x.width + x.length * x.height + x.width * x.height) * 2 << " volume=" <<  x.length * x.width * x.height << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}

void outputCylinder(ostream& out, const Cylinder& x)
{
  const double PI = 3.14159;
  out << "CYLINDER radius=" << x.radius << " height=" << x.height;
  out.setf(ios::fixed);
  out.precision(2);
  out << " surface area=" << 2 * x.radius * x.radius * PI + 2 * x.radius * PI * x.height << " volume=" << x.radius * x.radius * PI * x.height << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}

void outputPrism(ostream& out, const Prism& x)
{
  out << "PRISM side=" << x.side << " height=" << x.height;
  out.setf(ios::fixed);
  out.precision(2);
  out << " surface area=" << sqrt(3) * x.side * x.side / 4 * 2 + 3 * x.side * x.height << " volume=" << sqrt(3) * x.side * x.height << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}