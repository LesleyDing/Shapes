//Programmer name: Hanzhi Ding
//Programmer's ID: 1466750

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

// prototypes
vector<string> parseString(string);

int main()
{
  // programmer's identification
  cout << "Programmer: Hanzhi Ding\n";
  cout << "Programmer's ID: 1466750\n";
  cout << "File: " << __FILE__ << endl;

  // create a file-reading object
  ifstream fin;
  ofstream fout;
  fin.open("Shapes.input.txt"); // open the input file
  fout.open("Shapes.output.txt"); // open a file for output

  string input;

  if (fin.good()) // check if the input can be open
  {
    while (!fin.eof())
	{
	  getline(fin,input);
  	  vector<string>tokens = parseString(input); // parse the text to string
	  
	  if (tokens.size() != 0 && tokens[0] != "EOF") // skip over the blank and the end line of the file
	  {
		// check square and output data 
		if (tokens[0] == "SQUARE")
	    {
		  double s;
		  if (tokens.size() >= 2)
			s = atof(tokens[1].c_str());
		  else 
		    s = 0;
		  
		  double a = s * s;
		  double p = s * 4;

		  // console output
		  cout << "SQUARE side=" << s;
		  cout.setf(ios::fixed);
		  cout.precision(2);
		  cout << " area=" << a << " perimeter=" << p << endl;
		  cout.unsetf(ios::fixed);
		  cout.precision(6);

		  // file output
		  fout << "SQUARE side=" << s;
		  fout.setf(ios::fixed);
		  fout.precision(2);
		  fout << " area=" << a << " perimeter=" << p << endl;
		  fout.unsetf(ios::fixed);
		  fout.precision(6);
		}

		// check rectangle and output data
		else if (tokens[0] == "RECTANGLE")
		{
		  double l, w;
		  if (tokens.size() >= 3)
		  {	
			l = atof(tokens[1].c_str());
		    w = atof(tokens[2].c_str());
		  }
		  else if (tokens.size() == 2)
		  {	
			l = atof(tokens[1].c_str());
		    w = 0;
		  }
		  else
		  {	
			l = 0;
		    w = 0;
		  }
		  
		  double a = l * w;
		  double p = 2 * (l + w);
		  
		  // console output
		  cout << "RECTANGLE length=" << l << " width=" << w;
		  cout.setf(ios::fixed);
		  cout.precision(2);
		  cout << " area=" << a << " perimeter=" << p << endl;
		  cout.unsetf(ios::fixed);
		  cout.precision(6);

		  // file output
		  fout << "RECTANGLE length=" << l << " width=" << w;
		  fout.setf(ios::fixed);
		  fout.precision(2);
		  fout << " area=" << a << " perimeter=" << p << endl;
		  fout.unsetf(ios::fixed);
		  fout.precision(6);
		}
		
		// check circle and output data
		else if (tokens[0] == "CIRCLE")
		{
		  const double PI = 3.14159;
	      double r;
		  if (tokens.size() >= 2)  
		    r = atof(tokens[1].c_str());
		  else
		    r = 0;
		  
		  double a = r * r * PI;
		  double p = 2 * r * PI;
		  
		  // console output
		  cout << "CIRCLE radius=" << r;
		  cout.setf(ios::fixed);
		  cout.precision(2);
		  cout << " area=" << a << " perimeter=" << p << endl;
		  cout.unsetf(ios::fixed);
		  cout.precision(6);

		  // file output
		  fout << "CIRCLE radius=" << r;
		  fout.setf(ios::fixed);
		  fout.precision(2);
		  fout << " area=" << a << " perimeter=" << p << endl;
		  fout.unsetf(ios::fixed);
		  fout.precision(6);
		}

		// check triangle and output data
		else if (tokens[0] == "TRIANGLE")
		{
		  double s;
		  if (tokens.size() >= 2)
			s = atof(tokens[1].c_str());
		  else 
		    s = 0;

		  double a = sqrt(3) * s * s / 4;
		  double p = 3 * s;
		  
		  // console output
		  cout << "TRIANGLE side=" << s;
		  cout.setf(ios::fixed);
		  cout.precision(2);
		  cout << " area=" << a << " perimeter=" << p << endl;
		  cout.unsetf(ios::fixed);
		  cout.precision(6);

		  // file output
		  fout << "TRIANGLE side=" << s;
		  fout.setf(ios::fixed);
		  fout.precision(2);
		  fout << " area=" << a << " perimeter=" << p << endl;
		  fout.unsetf(ios::fixed);
		  fout.precision(6);
		}
		
		// check cube and output data
		else if (tokens[0] == "CUBE")
		{
		  double s;
		  if (tokens.size() >= 2)
			s = atof(tokens[1].c_str());
		  else 
		    s = 0;

		  double sa = s * s * 6;
		  double v = s * s * s;
		  
		  // console output
		  cout << "CUBE side=" << s;
		  cout.setf(ios::fixed);
		  cout.precision(2);
		  cout << " surface area=" << sa << " volume=" << v << endl;
		  cout.unsetf(ios::fixed);
		  cout.precision(6);

		  // file output
		  fout << "CUBE side=" << s;
		  fout.setf(ios::fixed);
		  fout.precision(2);
		  fout << " surface area=" << sa << " volume=" << v << endl;
		  fout.unsetf(ios::fixed);
		  fout.precision(6);
		}
		
		// check box and output data
		else if (tokens[0] == "BOX")
		{
		  double l, w, h;
		  if (tokens.size() >= 4)
		  {	
			l = atof(tokens[1].c_str());
		    w = atof(tokens[2].c_str());
			h = atof(tokens[3].c_str());
		  }
		  else if (tokens.size() == 3)
		  {	
			l = atof(tokens[1].c_str());
		    w = atof(tokens[2].c_str());
			h = 0;
		  }
		  else if (tokens.size() == 2)
		  {	
			l = atof(tokens[1].c_str());
		    w = 0;
			h = 0;
		  }
		  else
		  {	
			l = 0;
		    w = 0;
			h = 0;
		  }

		  double sa = (l * w + l * h + w * h) * 2;
		  double v = l * w * h;
		  
		  // console output
		  cout << "BOX length=" << l << " width=" << w << " height=" << h;
		  cout.setf(ios::fixed);
		  cout.precision(2);
		  cout << " surface area=" << sa << " volume=" << v << endl;
		  cout.unsetf(ios::fixed);
		  cout.precision(6);

		  // file output
		  fout << "BOX length=" << l << " width=" << w << " height=" << h;
		  fout.setf(ios::fixed);
		  fout.precision(2);
		  fout << " surface area=" << sa << " volume=" << v << endl;
		  fout.unsetf(ios::fixed);
		  fout.precision(6);
		}

		// check cylinder and output data
		else if(tokens[0] == "CYLINDER")
		{
		  const double PI = 3.14159;
		  double r, h;
		  if (tokens.size() >= 3)
		  {	
			r = atof(tokens[1].c_str());
		    h = atof(tokens[2].c_str());
		  }
		  else if (tokens.size() == 2)
		  {	
			r = atof(tokens[1].c_str());
		    h = 0;
		  }
		  else
		  {	
			r = 0;
		    h = 0;
		  }
		  
		  double sa = 2 * r * r * PI + 2 * r * PI * h;
		  double v = r * r * PI * h;
		  
		  // console output
		  cout << "CYLINDER radius=" << r << " height=" << h;
		  cout.setf(ios::fixed);
		  cout.precision(2);
		  cout << " surface area=" << sa << " volume=" << v << endl;
		  cout.unsetf(ios::fixed);
		  cout.precision(6);

		  // file output
		  fout << "CYLINDER radius=" << r << " height=" << h;
		  fout.setf(ios::fixed);
		  fout.precision(2);
		  fout << " surface area=" << sa << " volume=" << v << endl;
		  fout.unsetf(ios::fixed);
		  fout.precision(6);
		}
		
		// check prism and output data
		else if (tokens[0] == "PRISM")
		{
		  double s, h;
		  if (tokens.size() >= 3)
		  {	
			s = atof(tokens[1].c_str());
		    h = atof(tokens[2].c_str());
		  }
		  else if (tokens.size() == 2)
		  {	
			s = atof(tokens[1].c_str());
		    h = 0;
		  }
		  else
		  {	
			s = 0;
		    h = 0;
		  }

		  double sa = sqrt(3) * s * s / 4 * 2 + 3 * s * h;
		  double v = sqrt(3) * s * h;

		  // console output
		  cout << "PRISM side=" << s << " height=" << h;
		  cout.setf(ios::fixed);
		  cout.precision(2);
		  cout << " surface area=" << sa << " volume=" << v << endl;
		  cout.unsetf(ios::fixed);
		  cout.precision(6);

		  // file output
		  fout << "PRISM side=" << s << " height=" << h;
		  fout.setf(ios::fixed);
		  fout.precision(2);
		  fout << " surface area=" << sa << " volume=" << v << endl;
		  fout.unsetf(ios::fixed);
		  fout.precision(6);
		}
		
		// ignore the unknown shape
		else
		  // console output, and no file output for invalid object
		  cout << tokens[0] << " invalid object" << endl;
      }
 
	}

  }

  fin.close();
  fout.close();

}

// parseString function
vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}




