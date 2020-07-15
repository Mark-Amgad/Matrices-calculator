// Test2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std ;
// my_vec.push_back(4) ==> the result is : add 4 to my_vec 
// my_vec.size() ==> the result is size of my_vec
// my_vec.at(2) ==> the result is the element number 3 in my_vec ===== my_vec[2]
// my_vec.begin() ==> the result is the first element in my_vec 
// my_vec.insert(my_vec.begin(),5) ==> the result is add an 5 before the first element in my_vec
// my_vec.erase(my_vec.begin()+1) ===> the result is erase the element number 2 in my_vec 
// my_vec.clear()===> remove all elements in my vector
// my_vec.empty()===> that is check if my_vec is empty or not 
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

vector<vector<float> > get_my_vec(string my_str,int siz)
	
{
	vector<vector<float> >my_vec; //2D vector
	vector<float>row; // 1D vector
	string my_element; // the number in string before convert it to float
	int rows = 0;  
	float my_new_element; //the number in float aftr converting
	my_vec.push_back(row); //make 2D vector
	for (int j = 1; j < siz; j++) //loop to check all elements of string except the first element ( [ )
	{  
		// to understand code .. you should start from the last condition ( else condition )

		if (my_str[j] == ' ')  //if the char is space 
		{
			my_vec[rows].push_back(my_new_element); //.. save my_new_element in new column
			my_element.clear();  //we save the elemnt then ..clear this string to replace another element 
			//columns++;
		}
		if (my_str[j] == ']')   //if we arrive in the last index ..save my_new_element in new column
		{
			my_vec[rows].push_back(my_new_element); //.. save my_new_element in new column
			my_element.clear(); //we save the elemnt then ..clear this string to replace another element
		}
		if (my_str[j] == ';')  //if the char is ; ..that mean that w need to add our element in new column
		{                       // and save the row and go to the new row
			my_vec[rows].push_back(my_new_element); // save our element in new column in the same row
			my_element.clear();  // clear my_element variavle to recive a new one
			my_vec.push_back(row); // we add the row in 2D vector
			rows++;   // we go to a new row to get new values
		}

		else if (my_str[j] != ' ') // if the char is number
		{
			my_element.push_back(my_str[j]); // if number put it in string element 
			my_new_element = atof(my_element.c_str());//convert it to float and variable name will be my_new_element

		}

	}

	

	return my_vec; //return 2D vector
}
bool plus_and_minus_check( int rows_1, int colms_1,int rows_2,int colms_2)
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
bool power_and_determenant_check(int rows_1, int colms_1)
{
	if (rows_1 == colms_1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool transopse_check(vector<vector<float> >new_vec_1)
{
	int number_of_rows=0;
	int number_of_rows_2=0;
	bool check=1;
	for (int i = 0; i < new_vec_1.size(); i++)
	{
		
		number_of_rows = new_vec_1[i].size();

		if(i!=new_vec_1.size()-1)
		number_of_rows_2 = new_vec_1[i + 1].size();

		if (number_of_rows != number_of_rows_2)
		{
			check = 0;
		}
		
		
		
	}
	return check;
}
float determenant_operator(vector<vector<float> >new_vec_1)
{
	int columns = new_vec_1.size();


	for (int i = new_vec_1.size() - 1; i > 0; i--)
	{
		for (int j = 0; j < columns - 1; j++)
		{
			float val1 = new_vec_1[i][j];
			float val2 = new_vec_1[i][j + 1];
			float final_val = val1 / val2;

			for (int k = 0; k < new_vec_1.size(); k++)
			{

				new_vec_1[k][j] = new_vec_1[k][j] - (new_vec_1[k][j + 1] * final_val);
			}



		}
		columns--;
	}




	float total = 1;
	for (int i = 0; i < new_vec_1.size(); i++)
	{
		total = total * new_vec_1[i][i];
	}
	return total;
}
bool inverse_check(vector<vector<float> >new_vec_1)
{
	int rows = new_vec_1.size();
	int columns = new_vec_1[0].size();
	if (rows == columns)
		return 1;
	else
		return 0;
}
bool det_not_equal_zero_check(vector<vector<float> >new_vec_1)
{
	float det = determenant_operator(new_vec_1);
	if (det != 0)
	  return 1;
	else
	  return 0;
}

vector<vector<float> > plus_operator(vector<vector<float> >new_vec_1, int rows_1, int colms_1,
	                             vector<vector<float> >new_vec_2, int rows_2, int colms_2)
{
	
	vector<vector<float> > output_vec;
	vector<float> output_row;

	
	
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

vector<vector<float> > minus_operator(vector<vector<float> >new_vec_1, int rows_1, int colms_1,
	vector<vector<float> >new_vec_2, int rows_2, int colms_2)
{

	vector<vector<float> > output_vec;
	vector<float> output_row;



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

vector<vector<float> > multiply_operator(vector<vector<float> >new_vec_1, int rows_1, int colms_1,
	vector<vector<float> >new_vec_2, int rows_2, int colms_2)
{
	

	vector<vector<float> > output_vec; // output matrix (2D vector )
	vector<float>output_row;  // 1D vector 


	
		for (int i = 0; i < rows_1; i++)
		{
			for (int j = 0; j < colms_2; j++)
			{
				
				float x = 0;   // it's the total result of multiply for element
				for (int k = 0; k < colms_1; k++)
				{
					x = x + (new_vec_1[i][k])*(new_vec_2[k][j]); // sequance in multiply 


				}
				output_row.push_back(x);
				


			}
			output_vec.push_back(output_row);
			output_row.clear();
			
		}

		return output_vec;
	
	

}

vector<vector<float> >power_operator(vector<vector<float> >new_vec_1, int rows_1, int colms_1,int pow_num)
{

	vector<vector<float> > output_vec; // output matrix (2D vector )
	vector<float>output_row;  // 1D vector 

	vector<vector<float> > new_vec_2; // output matrix (2D vector )
	vector<float>new_row_2;  // 1D vector 

	new_vec_2.clear();
	new_row_2.clear();

	for (int i2 = 0; i2 < rows_1; i2++)
	{
		for (int j2 = 0; j2 < colms_1; j2++)
		{
			new_row_2.push_back(new_vec_1[i2][j2]);

		}
		new_vec_2.push_back(new_row_2);
		new_row_2.clear();

	}


	for (int count_power = 0; count_power < pow_num - 1; count_power++)
	{

		output_vec.clear();


		for (int i = 0; i < rows_1; i++)
		{
			for (int j = 0; j < colms_1; j++)
			{

				float x = 0;   // it's the total result of multiply for element
				for (int k = 0; k < colms_1; k++)
				{
					x = x + (new_vec_1[i][k])*(new_vec_2[k][j]); // sequance in multiply 



				}




				output_row.push_back(x);



			}

			output_vec.push_back(output_row);
			output_row.clear();

		}


		new_vec_2.clear();
		new_row_2.clear();

		for (int i3 = 0; i3 < rows_1; i3++)
		{
			for (int j3 = 0; j3 < colms_1; j3++)
			{
				new_row_2.push_back(output_vec[i3][j3]);

			}
			new_vec_2.push_back(new_row_2);
			new_row_2.clear();
		}



	}

	return output_vec;
}

vector<vector<float> >transpose_operator(vector<vector<float> >new_vec_1, int rows_1, int colms_1)
{
	vector<vector<float> > output_vec; // output matrix (2D vector )
	vector<float>output_row;  // 1D vector 

	for (int i = 0; i < colms_1; i++)
	{
		for (int j = 0; j < rows_1; j++)
		{
			output_row.push_back(new_vec_1[j][i]);
	    }
		output_vec.push_back(output_row);
		output_row.clear();
	}
	return output_vec;
}

float get_coFactor_2(vector<vector<float> > vec_part)
{
	float myCof = (vec_part[0][0] * vec_part[1][1]) - (vec_part[0][1] * vec_part[1][0]);
	return myCof;


}





float get_coFactor(vector<vector<float> >vec_part, int i, int j)
{
	float my_coff = 0;
	vector<vector<float> >temp;
	vector<float>  row_temp;

	if (vec_part.size() == 2)
	{
		get_coFactor_2(vec_part);
	}
	else if (vec_part.size() > 2)
	{
		for (int a = 0; a < vec_part.size(); a++)

		{
			for (int b = 0; b < vec_part.size(); b++)
			{
				if ((i != a) && (j != b))
				{

					row_temp.push_back(vec_part[a][b]);
				}
			}
			if (row_temp.size() > 0)
			{
				temp.push_back(row_temp);
				row_temp.clear();
			}
		}


	}











	if (temp.size() > 2)
	{


		my_coff = determenant_operator(temp);



	}
	else
	{
		my_coff = determenant_operator(temp);

	}



	return my_coff;
}



vector<vector<float> >get_adj(vector<vector<float> >my_new_vec_1)
{
	vector<vector<float> >adj_vec;
	vector<float> row_adj;
	int x = 1;

	if (my_new_vec_1.size() > 2)
	{

		for (int i = 0; i < my_new_vec_1.size(); i++)
		{
			for (int j = 0; j < my_new_vec_1.size(); j++)
			{
				row_adj.push_back(x*get_coFactor(my_new_vec_1, i, j));
				x = -x;
			}
			adj_vec.push_back(row_adj);
			if (my_new_vec_1.size() % 2 == 0)
				x = -x;
			else
				x = x;
			row_adj.clear();

		}

	}
	else
	{
		row_adj.push_back(my_new_vec_1[1][1]);
		row_adj.push_back(-1 * my_new_vec_1[1][0]);
		adj_vec.push_back(row_adj);
		row_adj.clear();
		row_adj.push_back(-1 * my_new_vec_1[0][1]);
		row_adj.push_back(my_new_vec_1[0][0]);
		adj_vec.push_back(row_adj);
		row_adj.clear();

	}
	return adj_vec;
}


vector<vector<float> > get_iverse(vector<vector<float> > my_new_vec_1)
{
	vector<vector<float> > output_vec;

	//x = { {1,2},{3,4} };
	//x = {{2,-1,0},{0,1,2},{1,1,0}};
	//x = {{1,2,2,3},{3,1,1,2},{2,2,3,1},{1,1,1,1}};
	float Det = determenant_operator(my_new_vec_1);


	output_vec = get_adj(my_new_vec_1);
	output_vec = transpose_operator(output_vec, output_vec.size(), output_vec.size());


	for (int i = 0; i < output_vec.size(); i++)
	{
		for (int j = 0; j < output_vec.size(); j++)
		{
			output_vec[i][j] = output_vec[i][j] / (Det);
		}

	}
	return output_vec;

}
vector<vector<float> > devider_operator(vector<vector<float> > my_new_vec_1, vector<vector<float> >new_vec_2)
{
	vector<vector<float> > output_vec; // output matrix (2D vector );

	int rows_1 = my_new_vec_1.size();
	int columns_1 = my_new_vec_1[0].size();

	new_vec_2 = get_iverse(new_vec_2);
	int rows_2 = new_vec_2.size();
	int columns_2 = new_vec_2[0].size();

	output_vec = multiply_operator(my_new_vec_1, rows_1, columns_1, new_vec_2, rows_2, columns_2);
	return output_vec;
}


string the_result_string(vector<vector<float> >output_vec)
{ // to conver matrix to string in foramt "[1 2;14 41; ... ]"

	int output_rows = output_vec.size(); // rows of matrix
	int output_colms = output_vec[0].size(); // columns of matrix

	string the_string_result; // the string that will contain the final output
	the_string_result.push_back('['); // first element in string should be "["
	for (int i = 0; i < output_rows; i++)
	{
		for (int j = 0; j < output_colms; j++)
		{
			string vec_element; // the string that will contain number but in form of string
			ostringstream ss; // to convert from float to string
			ss << output_vec[i][j]; //to get float element
			vec_element = ss.str(); // convert it to string
			the_string_result = the_string_result + vec_element;//add number ( in form of string )
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
	vector<vector<float> > new_vec_1;  //declaring for first matrix
	vector<vector<float> > new_vec_2; // seconde matrix (vector)



	string my_str; // first matrix from user in string
	int siz_1;    // size of first string matrix my_str

	string my_str_2; // second matrix from user in string
	int siz_2;    // size of second string matrix my_str

	int rows_1;   // number of rows of the first matrix (vector) new_vec_1
	int colms_1;  // number of columns of the first matrix (vector) new_vec_1

	int rows_2; //number of rows of the second matrix
	int colms_2; //number of columns of the second matrix

	string user_operator; //the output from function that get the user operator

	string the_string_result; // the string that will be the output of the program (final result)

	my_str = get_user_input();  //get the first string from user
	siz_1 = my_str.length();   //get size of the first string from user



	new_vec_1 = get_my_vec(my_str, siz_1);  // convert this string to float 2D vector
	rows_1 = new_vec_1.size();              //get number of rows of the first vector(new_vec_1) 
	colms_1 = new_vec_1[0].size();          //get number of columns of the first vector(new_vec_1)



	bool check;

	user_operator = get_user_operator();  // get user operator

	if (user_operator == "+")
	{
		my_str_2 = get_user_input();
		siz_2 = my_str_2.length();

		new_vec_2 = get_my_vec(my_str_2, siz_2); // convert this is string into matrix (2D vector)
		rows_2 = new_vec_2.size(); // number of matrix's rows
		colms_2 = new_vec_2[0].size(); // number of matrix's columns


		check = plus_and_minus_check(rows_1, colms_1, rows_2, colms_2);
		if (check)
		{
			vector<vector<float> > output_vec;  // declaring for result matrix
			output_vec = plus_operator(new_vec_1, rows_1, colms_1, new_vec_2, rows_2, colms_2);
			//plus operator take two matices and no. of rwos and colms of each other

			the_string_result = the_result_string(output_vec); //convert the output_vec to string 

			cout << the_string_result << endl;

		}
		else
		{
			cout << "ERROR" << endl;
		}
		//from user and convert it to 2D vector then do the plus operator and return output_vec 

	}
	else if (user_operator == "-")
	{

		my_str_2 = get_user_input();
		siz_2 = my_str_2.length();

		new_vec_2 = get_my_vec(my_str_2, siz_2); // convert this is string into matrix (2D vector)
		rows_2 = new_vec_2.size(); // number of matrix's rows
		colms_2 = new_vec_2[0].size(); // number of matrix's columns

		check = plus_and_minus_check(rows_1, colms_1, rows_2, colms_2);
		if (check)
		{
			vector<vector<float> > output_vec;  // declaring for result matrix
			output_vec = minus_operator(new_vec_1, rows_1, colms_1, new_vec_2, rows_2, colms_2);
			//plus operator take two matices and no. of rwos and colms of each other

			the_string_result = the_result_string(output_vec); //convert the output_vec to string 

			cout << the_string_result << endl;
		}
		else
		{
			cout << "ERROR" << endl;
		}

	}
	else if (user_operator == "*")
	{
		my_str_2 = get_user_input();
		siz_2 = my_str_2.length();

		new_vec_2 = get_my_vec(my_str_2, siz_2); // convert this is string into matrix (2D vector)
		rows_2 = new_vec_2.size(); // number of matrix's rows
		colms_2 = new_vec_2[0].size(); // number of matrix's columns

		check = mutiply_check(rows_1, colms_1, rows_2, colms_2);
		if (check)
		{
			vector<vector<float> > output_vec;  // declaring for result matrix
			output_vec = multiply_operator(new_vec_1, rows_1, colms_1, new_vec_2, rows_2, colms_2);
			//plus operator take two matices and no. of rwos and colms of each other

			the_string_result = the_result_string(output_vec); //convert the output_vec to string 

			cout << the_string_result << endl;
		}
		else
		{
			cout << "ERROR" << endl;
		}

	}
	
	else if (user_operator == "^")
	{
		int pow_num;
		check = power_and_determenant_check(rows_1, colms_1);
		if (check)
		{
			cin >> pow_num;
					if (pow_num > 0)
					{
						vector<vector<float> > output_vec;  // declaring for result matrix
						output_vec = power_operator(new_vec_1, rows_1, colms_1, pow_num);
						//plus operator take two matices and no. of rwos and colms of each other

						the_string_result = the_result_string(output_vec); //convert the output_vec to string

						cout << the_string_result << endl;
					}
					else
					{
						cout << "ERROR" << endl;
					}
		}
		else
		{
			cout << "ERROR" << endl;
		}
	}



	else if(user_operator=="T")
	{
	     check = transopse_check(new_vec_1);
		 if (check)
		 {
			 vector<vector<float> > output_vec;

			 output_vec = transpose_operator(new_vec_1, rows_1, colms_1);
			 the_string_result = the_result_string(output_vec);
			 cout << the_string_result << endl;
		 }
		 else
		 {
			 cout << "ERROR" << endl;
		 }

    }


	else if (user_operator == "D")
	{
	      check = power_and_determenant_check(rows_1, colms_1);
		  if (check)
		  {
			  float det_result;
			  det_result = determenant_operator(new_vec_1);
			  cout << det_result << endl;
		  }
		  else
		  {
			  cout << "ERROR" << endl;
		  }
    }

	else if (user_operator == "I")
	{

	

	

	check = inverse_check(new_vec_1);
	if (check)
	{
		if (det_not_equal_zero_check)
		{
			vector<vector<float> > output_vec;  // declaring for result matrix
			output_vec = get_iverse(new_vec_1);
			//plus operator take two matices and no. of rwos and colms of each other

			the_string_result = the_result_string(output_vec); //convert the output_vec to string 

			cout << the_string_result << endl;
		}
	}
	else
	{
		cout << "ERROR" << endl;
	}

	}
	else if (user_operator == "/")
	{
		if (power_and_determenant_check)
		{
			my_str_2 = get_user_input();
			siz_2 = my_str_2.length();

			new_vec_2 = get_my_vec(my_str_2, siz_2); // convert this is string into matrix (2D vector)
			rows_2 = new_vec_2.size(); // number of matrix's rows
			colms_2 = new_vec_2[0].size(); // number of matrix's columns

			check = (power_and_determenant_check(rows_2, colms_2) && det_not_equal_zero_check(new_vec_2)&&(colms_1==rows_2));
			if (check)
			{
				vector<vector<float> > output_vec;  // declaring for result matrix
				output_vec = devider_operator(new_vec_1, new_vec_2);
				//plus operator take two matices and no. of rwos and colms of each other

				the_string_result = the_result_string(output_vec); //convert the output_vec to string 

				cout << the_string_result << endl;
			}
			else
			{
				cout << "ERROR" << endl;
			}
		}
		else
		{
			cout << "ERROR" << endl;
		}

	}


	


	}














	
	
		
	
		//my_str = "[10 10;5 5]";
		         //"[20 3.5;5 -5]"
	//output_vec=plus_operator(new_vec_1, rows_1, colms_1);

	
	
	
		
			
	

	//float a;
	//a = atof(x.c_str());
	//cout << a << endl;




	//float f;
	//f = 15.5;
	//string s;
	//ostringstream ss; //  declare variable to take float read
	//ss << f;        // to put the flat value in variable
	//s = ss.str();   // to convert this variable to string 
	//cout << s[1] << endl;





	


	//my_vec.push_back(1);
	//my_vec.push_back(2);
	//my_vec.push_back(3);
	//my_vec.push_back(4);
	//my_vec.push_back(5);
	//my_vec.push_back(6);
	
	
	//int len;
	//len = my_vec.size();
	//for (int i = 0; i < len; i++)
	//{
		//cout << my_vec[i] << " ";
	//}
	
	

	



