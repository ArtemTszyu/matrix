#include <iostream>

int main ()
{
	int matrix[3][3], matrix1[3][3], matrix2[3][3];
	char op, op1;
	
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
	 	{	 
	 	std::cin >> matrix1[i][j];
	 	std::cin.get(op);
	 	
	 	if ((op == '\n') && (i!=2 && j != 2)) {std::cout << "\aAn error has occured while reading input data"; return 0;}
	 	}
	}
	
	std::cin >> op1; 
	
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
	 	{	 
	 	std::cin >> matrix2[i][j];
	 	std::cin.get(op);
	 	
	 	if ((op == '\n') && (i!=2 && j != 2)) {std::cout << "\aAn error has occured while reading input data"; return 0;}
	 	}
	}
	
	switch (op1)
	{
		case '+': 
		{
			for (int i = 0; i<3; i++)
			{
	 			for (int j = 0; j<3; j++)
				{
	 		  		matrix[i][j] = matrix1[i][j]+matrix2[i][j];
				}
			}
			
			break;
		}
		
		case '-': 
		{
			for (int i = 0; i<3; i++)
			{
	 			for (int j = 0; j<3; j++)
				{
				 	matrix[i][j] = matrix1[i][j]-matrix2[i][j];
				}
			}
			
	 		break;
		}
		
		case '*': 
		{
			for( int i = 0; i < 3; ++i )
			{
    				for( int j = 0; j < 3; ++j )
				{
      		  			int result = 0;
      		   				for( int k = 0; k < 3; ++k )
						{
       			 				result += matrix1[i][k] * matrix2[k][j];
      		   				}
      		  				matrix[i][j] = result;
    		 		}
  			}
      
	 		std::cout << std::endl;
	 		
	 		break;
		}
		
		default: {std::cout << "\aAn error has occured while reading input data"; return 0;}
	}

	for (int i = 0; i<3; i++)
	{
	 	for (int j = 0; j<3; j++)
	 	{
		    std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}

	return 0;
}
