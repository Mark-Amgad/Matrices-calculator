// test3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;


string get_user_input()
{
	string my_str;
	getline(cin, my_str);
	return my_str;
} // get string from user

string get_user_operator()
{
	string user_operator;

	getline(cin, user_operator);
	return user_operator;
} //get string(operator) from user

vector<vector<double> > get_my_vec_img(string my_str, int siz)
{
	vector<vector<double> > img_vec;
	vector<double> img_row;
	
	int num_of_columns=0;
	string my_img;
	double my_img_num;

	for (int i = 1; i < siz; i++)
	{
		if(my_str[i] == ' ')  //if the char is space 
		{
			if (my_str[i - 1] == 'i')
			{
				int x = my_img.find('+');
				x = my_img.find('+');

				int y = my_img.find('-');
				y = my_img.find('-');
				if (y == 0)
				{
					string s = my_img.substr(1, my_img.length() - 1);
					int y2 = s.find('-');
					if (y2 > 0)
					{
						y = y2+1;
					}
				}
				if (x > 0)
				{
					my_img.erase(my_img.begin() + 0, my_img.begin()+x);
				}
				else if (y > 0)
				{
					my_img.erase(my_img.begin() + 0, my_img.begin()+y);
				}
				

			}

			//else
			//{
				//my_img = "0";
			//}

			my_img_num = atof(my_img.c_str());
			img_row.push_back(my_img_num); //.. save my_new_element in new column
			my_img.clear();  //we save the elemnt then ..clear this string to replace another element 
			//columns++;

		}
		if (my_str[i] == ']')   //if we arrive in the last index ..save my_new_element in new column
		{
			if (my_str[i - 1] == 'i')
			{
				int x = my_img.find('+');
				x = my_img.find('+');

				int y = my_img.find('-');
				y = my_img.find('-');
				if (y == 0)
				{
					string s = my_img.substr(1, my_img.length() - 1);
					int y2 = s.find('-');
					if (y2 > 0)
					{
						y = y2 + 1;
					}
				}

				if (x > 0)
				{
					my_img.erase(my_img.begin() +0, my_img.begin()+x);
				}
				else if (y > 0)
				{
					my_img.erase(my_img.begin() + 0, my_img.begin()+y);
				}
				

			}
			else
			{
				my_img="0";
			}
			my_img_num = atof(my_img.c_str());
			img_row.push_back(my_img_num); //.. save my_new_element in new column
			my_img.clear(); //we save the elemnt then ..clear this string to replace another element
			img_vec.push_back(img_row);
			img_row.clear();

		}
		if (my_str[i] == ';')  //if the char is ; ..that mean that w need to add our element in new column
		{                       // and save the row and go to the new row
			if (my_str[i - 1] == 'i')
			{
				int x = my_img.find('+');
				x = my_img.find('+');

				int y = my_img.find('-');
				y = my_img.find('-');
				if (y == 0)
				{
					string s = my_img.substr(1, my_img.length() - 1);
					int y2 = s.find('-');
					if (y2 > 0)
					{
						y = y2 + 1;
					}
				}


				if (x > 0)
				{
					my_img.erase(my_img.begin() + 0, my_img.begin()+x);
				}
				else if (y > 0)
				{
					my_img.erase(my_img.begin() + 0, my_img.begin()+y);
				}
				
			}

			else
			{
				my_img="0";
			}
			my_img_num = atof(my_img.c_str());
			img_row.push_back(my_img_num); // save our element in new column in the same row
			my_img.clear();  // clear my_element variavle to recive a new one
			img_vec.push_back(img_row); // we add the row in 2D vector
			img_row.clear();


		}

		else if (my_str[i] != ' ') // if the char is number
		{
			my_img.push_back(my_str[i]); // if number put it in string element 
			//my_new_element = atof(my_element.c_str());//convert it to float and variable name will be my_new_element

		}

	}
	return img_vec;
}


vector<vector<double> > get_my_vec(string my_str, int siz)

{
	vector<vector<double> >my_vec; //2D vector
	vector<double>row; // 1D vector
	string my_element; // the number in string before convert it to float
	int rows = 0;
	double my_new_element; //the number in float aftr converting
	
	for (int j = 1; j < siz; j++) //loop to check all elements of string except the first element ( [ )
	{
		// to understand code .. you should start from the last condition ( else condition )

		if (my_str[j] == ' ')  //if the char is space 
		{
			if(my_str[j-1]=='i')
			{
				int x = my_element.find('+');
				x = my_element.find('+');

				int y = my_element.find('-');
				y = my_element.find('-');
				if (y == 0)
				{
					string s = my_element.substr(1, my_element.length() - 1);
					int y2 = s.find('-');
					if (y2 > 0)
					{
						y = y2+1;
					}
				}
				if (x > 0)
				{
					my_element.erase(my_element.begin() + x, my_element.end());
				}
				else if (y > 0)
				{
					my_element.erase(my_element.begin() + y, my_element.end());
				}
				

			}
			
				my_new_element = atof(my_element.c_str());
				row.push_back(my_new_element); //.. save my_new_element in new column
				my_element.clear();  //we save the elemnt then ..clear this string to replace another element 
				//columns++;
			
		}
		if (my_str[j] == ']')   //if we arrive in the last index ..save my_new_element in new column
		{
			if (my_str[j - 1] == 'i')
			{
				int x = my_element.find('+');
				x = my_element.find('+');

				int y = my_element.find('-');
				y = my_element.find('-');
				if (y == 0)
				{
					string s = my_element.substr(1, my_element.length() - 1);
					int y2 = s.find('-');
					if (y2 > 0)
					{
						y = y2 + 1;
					}
				}


				if (x > 0)
				{
					my_element.erase(my_element.begin() + x, my_element.end());
				}
				else if (y > 0)
				{
					my_element.erase(my_element.begin() + y, my_element.end());
				}
				else
				{
					my_element.clear();
				}

			}
			    my_new_element = atof(my_element.c_str());
				row.push_back(my_new_element); //.. save my_new_element in new column
				my_element.clear(); //we save the elemnt then ..clear this string to replace another element
				my_vec.push_back(row);
				row.clear();
			
		}
		if (my_str[j] == ';')  //if the char is ; ..that mean that w need to add our element in new column
		{                       // and save the row and go to the new row
			if (my_str[j - 1] == 'i')
			{
				int x = my_element.find('+');
				x = my_element.find('+');

				int y = my_element.find('-');
				y = my_element.find('-');
				if (y == 0)
				{
					string s = my_element.substr(1, my_element.length() - 1);
					int y2 = s.find('-');
					if (y2 > 0)
					{
						y = y2 + 1;
					}
				}


				if (x > 0)
				{
					my_element.erase(my_element.begin() + x, my_element.end());
				}
				else if (y > 0)
				{
					my_element.erase(my_element.begin() + y, my_element.end());
				}
				else
				{
					my_element.clear();
				}
			}
			    my_new_element = atof(my_element.c_str());
				row.push_back(my_new_element); // save our element in new column in the same row
				my_element.clear();  // clear my_element variavle to recive a new one
				my_vec.push_back(row); // we add the row in 2D vector
				row.clear();
			
			
		}

		else if (my_str[j] != ' ') // if the char is number
		{
			my_element.push_back(my_str[j]); // if number put it in string element 
			//my_new_element = atof(my_element.c_str());//convert it to float and variable name will be my_new_element

		}

	}



	return my_vec; //return 2D vector
}

bool plus_and_minus_check(int rows_1, int colms_1, int rows_2, int colms_2)
{

	if ((rows_1 == rows_2) && (colms_1 == colms_2))//cheack if no of rows and colums 
	{                                              //of first matrix are equal in the second matrix


		return 1;
	}
	else // if rows and columns aren't equal
	{

		return 0;
	}

}

bool mutiply_check(int rows_1, int colms_1, int rows_2, int colms_2)
{
	if ((colms_1 == rows_2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

vector<vector<double> > plus_operator(vector<vector<double> >new_vec_1, int rows_1, int colms_1,
	vector<vector<double> >new_vec_2, int rows_2, int colms_2)
{

	vector<vector<double> > output_vec;
	vector<double> output_row;



	for (int i = 0; i < rows_1; i++)
	{
		for (int j = 0; j < colms_1; j++)
		{
			output_row.push_back(new_vec_1[i][j] + new_vec_2[i][j]);
			//save values of columns in one row



		}
		// after this for loop save the 1D vector in 2D vector .. then clear to get new row
		output_vec.push_back(output_row);
		output_row.clear();

	}

	return output_vec;  // return output matrix 



}
vector<vector<double> > minus_operator(vector<vector<double> >new_vec_1, int rows_1, int colms_1,
	vector<vector<double> >new_vec_2, int rows_2, int colms_2)
{

	vector<vector<double> > output_vec;
	vector<double> output_row;



	for (int i = 0; i < rows_1; i++)
	{
		for (int j = 0; j < colms_1; j++)
		{
			output_row.push_back(new_vec_1[i][j] - new_vec_2[i][j]);
			//save values of columns in one row



		}
		// after this for loop save the 1D vector in 2D vector .. then clear to get new row
		output_vec.push_back(output_row);
		output_row.clear();

	}

	return output_vec;  // return output matrix 



}


vector<vector<double> > real_multiply_operator(vector<vector<double> >real_vec_1, int rows_1,int colms_1,
	vector<vector<double> >img_vec_1, vector<vector<double> >real_vec_2,int colms_2,
	vector<vector<double> >img_vec_2)
{


	vector<vector<double> > output_vec; // output matrix (2D vector )
	vector<double>output_row;  // 1D vector 



	for (int i = 0; i < rows_1; i++)
	{
		for (int j = 0; j < colms_2; j++)
		{

			double x = 0;   // it's the total result of multiply for element
			for (int k = 0; k < colms_1; k++)
			{
				x = x + ( (real_vec_1[i][k]*real_vec_2[k][j]) - (img_vec_1[i][k]*img_vec_2[k][j]) ); // sequance in multiply 


			}
			output_row.push_back(x);



		}
		output_vec.push_back(output_row);
		output_row.clear();

	}

	return output_vec;



}


vector<vector<double> > img_multiply_operator(vector<vector<double> >real_vec_1, int rows_1, int colms_1,
	vector<vector<double> >img_vec_1, vector<vector<double> >real_vec_2, int rows_2, int colms_2,
	vector<vector<double> >img_vec_2)
{


	vector<vector<double> > output_vec; // output matrix (2D vector )
	vector<double>output_row;  // 1D vector 



	for (int i = 0; i < rows_1; i++)
	{
		for (int j = 0; j < colms_2; j++)
		{

			double x = 0;   // it's the total result of multiply for element
			for (int k = 0; k < colms_1; k++)
			{
				x = x + ((real_vec_1[i][k] * img_vec_2[k][j]) + (img_vec_1[i][k] * real_vec_2[k][j])); // sequance in multiply 


			}
			output_row.push_back(x);



		}
		output_vec.push_back(output_row);
		output_row.clear();

	}

	return output_vec;



}




string the_result_string(vector<vector<double> > my_real_output_vec, vector<vector<double> > my_img_output_vec)
{ // to conver matrix to string in foramt "[1 2;14 41; ... ]"

	int output_rows = my_real_output_vec.size(); // rows of matrix
	int output_colms = my_real_output_vec[0].size(); // columns of matrix

	int output_rows_2 = my_img_output_vec.size(); // rows of matrix
	int output_colms_2 = my_img_output_vec[0].size(); // columns of matrix

	string the_string_result; // the string that will contain the final output
	the_string_result.push_back('['); // first element in string should be "["
	for (int i = 0; i < output_rows; i++)
	{
		for (int j = 0; j < output_colms; j++)
		{
			string vec_element_real; // the string that will contain number but in form of string
			string vec_element_img;
			ostringstream s_real,s_img; // to convert from float to string
			s_real << my_real_output_vec[i][j]; //to get float element
			s_img << my_img_output_vec[i][j];
			vec_element_real = s_real.str(); // convert it to string
			vec_element_img = s_img.str();

			if (my_real_output_vec[i][j] != 0)
			{
				the_string_result = the_string_result + vec_element_real;
			}
			
			
			if ((my_img_output_vec[i][j] > 0)&&(my_real_output_vec[i][j]!=0))
			{
				the_string_result = the_string_result + "+" + vec_element_img + "i";
			}
			else if ((my_img_output_vec[i][j] > 0) && (my_real_output_vec[i][j] == 0))
			{
				the_string_result = the_string_result +  vec_element_img + "i";
			}
			else if ((my_img_output_vec[i][j] < 0) && (my_real_output_vec[i][j] != 0))
			{
				the_string_result = the_string_result  + vec_element_img + "i";
			}
			else if ((my_img_output_vec[i][j] < 0) && (my_real_output_vec[i][j] == 0))
			{
				the_string_result = the_string_result + vec_element_img + "i";
			}
			
			//the_string_result = the_string_result + vec_element;//add number ( in form of string )
																//to the result string
			if (j != output_colms - 1) // when we aren't at the last element in row .. add space
			{
				the_string_result.push_back(' ');
			}
		}
		if (i != output_rows - 1)  //when we aren't in the last row in matrix . add ( ; )
		{
			the_string_result.push_back(';');
		}
	}
	the_string_result.push_back(']'); // add " ] " in the last of string 


	return the_string_result;
}


int main()
{
	string my_str = get_user_input();

	//string my_str2 = "[-2-5i 2+3i;2-3i 4+7i]";
	//[2-3i 4+7i;-4+3i 3-3i]
	int siz = my_str.size();
	//int siz2 = my_str2.size();
	string user_operator = get_user_operator();
//******************
	vector < vector<double> > my_real_vec_1;
	vector < vector<double> > my_img_vec_1;

	my_real_vec_1 = get_my_vec(my_str, siz);
	my_img_vec_1 = get_my_vec_img(my_str, siz);

	int rows1, columns1;
	rows1 = my_real_vec_1.size();
	columns1 = my_real_vec_1[0].size();
	//***********
	vector < vector<double> > my_real_vec_2;
	vector < vector<double> > my_img_vec_2;
	//*********
	vector < vector<double> > my_real_output_vec;
	vector < vector<double> > my_img_output_vec;


	if (user_operator == "+")
	{
		string my_str2 = get_user_input();
		int siz2 = my_str2.size();

		my_real_vec_2 = get_my_vec(my_str2, siz2);
		my_img_vec_2 = get_my_vec_img(my_str2, siz2);

		int rows2, columns2;
		rows2 = my_real_vec_2.size();
		columns2 = my_real_vec_2[0].size();


		if (plus_and_minus_check(rows1, columns1, rows2, columns2))
		{
			 my_real_output_vec = plus_operator(my_real_vec_1, rows1, columns1, my_real_vec_2, rows2, columns2);
			 my_img_output_vec = plus_operator(my_img_vec_1, rows1, columns1, my_img_vec_2, rows2, columns2);
			 cout << the_result_string(my_real_output_vec, my_img_output_vec) << endl;
		}
		else
		{
			cout << "ERROR" << endl;
		}
		
		
	}



	if (user_operator == "-")
	{
		string my_str2 = get_user_input();
		int siz2 = my_str2.size();

		my_real_vec_2 = get_my_vec(my_str2, siz2);
		my_img_vec_2 = get_my_vec_img(my_str2, siz2);

		int rows2, columns2;
		rows2 = my_real_vec_2.size();
		columns2 = my_real_vec_2[0].size();


		if (plus_and_minus_check(rows1, columns1, rows2, columns2))
		{
			my_real_output_vec = minus_operator(my_real_vec_1, rows1, columns1, my_real_vec_2, rows2, columns2);
			my_img_output_vec = minus_operator(my_img_vec_1, rows1, columns1, my_img_vec_2, rows2, columns2);
			cout << the_result_string(my_real_output_vec, my_img_output_vec) << endl;
		}
		else
		{
			cout << "ERROR" << endl;
		}


	}
	

	if (user_operator == "*")
	{
		string my_str2 = get_user_input();
		int siz2 = my_str2.size();

		my_real_vec_2 = get_my_vec(my_str2, siz2);
		my_img_vec_2 = get_my_vec_img(my_str2, siz2);

		int rows2, columns2;
		rows2 = my_real_vec_2.size();
		columns2 = my_real_vec_2[0].size();


		if (mutiply_check(rows1, columns1, rows2, columns2))
		{
			my_real_output_vec = real_multiply_operator(my_real_vec_1,rows1,columns1,
				my_img_vec_1,my_real_vec_2,columns2,my_img_vec_2);

			my_img_output_vec = img_multiply_operator(my_real_vec_1,rows1, columns1,
				my_img_vec_1, my_real_vec_2,rows2,columns2,my_img_vec_2);
			cout << the_result_string(my_real_output_vec, my_img_output_vec) << endl;
		}
		else
		{
			cout << "ERROR" << endl;
		}


	}
	

	

	//*******

	


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << my_real_vec_1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << my_img_vec_1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << my_real_vec_2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << my_img_vec_2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i <2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << my_real_output_vec[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << my_img_output_vec[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	//my_real_output_vec = plus_operator(my_real_vec_1, rows1, columns1, my_real_vec_2, rows2, columns2);
	//my_img_output_vec = plus_operator(my_img_vec_1, rows1, columns1, my_img_vec_2, rows2, columns2);

	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
