#include "picture.h"
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <climits>
using namespace std;
using std::vector;

int main()
{
	
	/*==================================*/
	/*======= Load data from file=======*/
	/*==================================*/

	string name;

	//car file
	name = "input/car.tga";
	picture car;
	car.readAll(name);

	//circles file
	name = "input/circles.tga";
	picture circles;
	circles.readAll(name);

	//blue file
	name = "input/layer_blue.tga";
	picture blue;
	blue.readAll(name);
	
	//green file
	name = "input/layer_green.tga";
	picture green;
	green.readAll(name);

	//red file
	name = "input/layer_red.tga";
	picture red;
	red.readAll(name);

	// layer1 file
	name = "input/layer1.tga";
	picture layer1;
	layer1.readAll(name);

	//layer2 file
	name = "input/layer2.tga";
	picture layer2;
	layer2.readAll(name);

	//pattern1 file
	name = "input/pattern1.tga";
	picture Pattern1;
	Pattern1.readAll(name);

	//pattern2 file
	name = "input/Pattern2.tga";
	picture Pattern2;
	Pattern2.readAll(name);

	//text file
	name = "input/text.tga";
	picture text;
	text.readAll(name);

	//text file2
	name = "input/text2.tga";
	picture text2;
	text2.readAll(name);

	/*==============================*/
	/*======= call functions =======*/
	/*==============================*/

	string out;
	
	/*======= Test 1 =======*/  //true
	picture mult;
	mult = layer1.Multiply(Pattern1);
	out = "output/part1.tga";
	mult.writeFile(out);

	cout << "Task 1 complete" << endl;

	/*======= Test 2 =======*/   //true
	picture subt;
	subt = car.Subtract(layer2);
	out = "output/part2.tga";
	subt.writeFile(out);

	cout << "Task 2 complete" << endl;

	/*======= Test 3 =======*/  //true
	picture temp;
	temp = layer1.Multiply(Pattern2);

	picture Screen;
	Screen = temp.Screen(text);
	out = "output/part3.tga";
	Screen.writeFile(out);

	cout << "Task 3 complete" << endl;

	/*======= Test 4 =======*/  //true
	temp = layer2.Multiply(circles);
	//out = "4A.tga";
	//temp.writeFile(out);

	picture four;
	four = temp.Subtract(Pattern2);
	out = "output/part4.tga";
	four.writeFile(out);

	cout << "Task 4 complete" << endl;

	/*======= Test 5 =======*/  //true
	picture ove;
	ove = layer1.Overlay(Pattern1);
	out = "output/part5.tga";
	ove.writeFile(out);

	cout << "Task 5 complete" << endl;

	/*======= Test 6 =======*/  //true
	picture add200;
	add200 = car.Sum(0, 200 ,0);
	out = "output/part6.tga";
	add200.writeFile(out);

	//cout << "Task 6 complete" << endl;

	/*======= Test 7 =======*/  //true
	picture Scaled;
	Scaled = car.ScaleRed(4.0f);
	Scaled = Scaled.ScaleBlue(0.0f);
	out = "output/part7.tga";
	Scaled.writeFile(out);

	cout << "Task 7 complete" << endl;

	/*======= Test 8 =======*/  //true
	out = "output/part8_r.tga";
	car.WriteRed(out);
	
	out = "output/part8_g.tga";
	car.WriteGreen(out);
	
	out = "output/part8_b.tga";
	car.WriteBlue(out);

	cout << "Task 8 complete" << endl;

	/*======= Test 9 =======*/  //true
	picture combo;
	combo = red.Combine(green, blue);
	out = "output/part9.tga";
	combo.writeFile(out);

	cout << "Task 9 complete" << endl;

	/*======= Test 10 =======*/  //true
	out = "output/part10.tga";
	text2.Rotate(out);

	cout << "Task 10 complete" << endl;

	return 0;
}
