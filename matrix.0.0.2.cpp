#include <iostream>

using namespace std;

void delete_pamyat (float** matrix, unsigned int rows) {
	for(unsigned int i=0; i<rows; i++){	
		delete []matrix[i];
	}			
	delete []matrix;
}

float** pamyat_dlya_matritzi(float** matrix, unsigned int rows, unsigned int columns){
	matrix = new float *[ rows ];
	for( unsigned int i = 0; i < rows; ++i ) {
    	matrix[ i ] = new float[ columns ];
   		for( unsigned int j = 0; j < columns; ++j ) {
     		matrix[ i ][ j ] = 0.0f;
   		}
	}
	return matrix;
}

void write_matrix (float** matrix, unsigned int rows3, unsigned int columns3) {
	for (unsigned int i=0; i<rows3; i++){
		for (unsigned int j=0; j<columns3; j++){
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

float ** read_matrix (unsigned int rows, unsigned int columns, float** matrix) {
	for (unsigned int i=0; i<rows; i++) {
		for (unsigned int j=0; j<columns; j++){
			cin >> matrix[i][j];
		}
	}
	return matrix;
}

bool gaus_obr(unsigned int rows_i_columns, float **matrix1, float **&matrix, bool &m) {
	int i, j, k; 
	matrix=pamyat_dlya_matritzi(matrix, rows_i_columns, rows_i_columns); 
	for(i=0; i<rows_i_columns; i++) {
		matrix[i][i]=1; 
	}
	float a, b;
	for(i=0; i<rows_i_columns; i++) {
		a=matrix1[i][i]; 
		for(j=i+1; j<rows_i_columns; j++) { 	
			b=matrix1[j][i]; 	
			for(k=0; k<rows_i_columns; k++) {
				matrix1[j][k]=matrix1[i][k]*b-matrix1[j][k]*a; 	
				matrix[j][k]=matrix[i][k]*b-matrix[j][k]*a; 
			} 
		} 
	} 
	float sum; 
	for(i=0; i<rows_i_columns; i++) {
		for(j=rows_i_columns-1; j>=0; j--) { 
			sum=0; 
			for(k=rows_i_columns-1; k>j; k--){ 	
				sum+=matrix1[j][k]*matrix[k][i]; 	
			}
			if(matrix1[j][j]==0) {	 
				delete_pamyat(matrix, rows_i_columns);
				cout << endl << "It is not the inverse matrix for this one";
				m=false;		
				return false;
			}
			matrix[j][i]=(matrix[j][i]-sum)/matrix1[j][j]; 
		} 
	} 
	return true; 
}

bool sum_matrix (float **matrix1, unsigned int rows1, unsigned int columns1, float **matrix2, unsigned int rows2, unsigned int columns2, float ** matrix, unsigned int rows3, unsigned int columns3, bool &m) {
	bool ok=false;		
	if (rows1 == rows2 && columns1 == columns2){		
		ok=true;		
		for (unsigned int i = 0; i<rows3; i++){
	 		for (unsigned int j = 0; j<columns3; j++){
	 		  	matrix[i][j] = matrix1[i][j]+matrix2[i][j];
			}
		}
	}
	else {
		cout << endl << "You can`t make this action";
		m=false;
	}
	return ok;
}

bool sub_matrix (float **matrix1, unsigned int rows1, unsigned int columns1, float **matrix2, unsigned int rows2, unsigned int columns2, float ** matrix, unsigned int rows3, unsigned int columns3, bool &m) {
	bool ok=false;	
	if (rows1 == rows2 && columns1 == columns2){		
		ok=true;		
		for (unsigned int i = 0; i<rows3; i++){
	 		for (unsigned int j = 0; j<columns3; j++){		
	 		  	matrix[i][j] = matrix1[i][j]-matrix2[i][j];
			}
		}
	}
	else {
		cout << endl << "You can`t make this action";
		m=false;
	}
	return ok;	
}

bool mul_matrix (float **matrix1, unsigned int rows1, unsigned int columns1, float **matrix2, unsigned int rows2, unsigned int columns2, float ** matrix, unsigned int rows3, unsigned int columns3, bool &m) {
	bool ok=false;
	if (columns1 == rows2) {	
		for( unsigned int i = 0; i < rows3; ++i ){	
    			for( unsigned int j = 0; j < columns3; ++j ){	
      		  		float result = 0.0f;
      		   		for( unsigned int k = 0; k < columns3; ++k ){
       			 		result += matrix1[i][k] * matrix2[k][j];
      		   		}
      		  		matrix[i][j] = result;
    			}
  		}
	 	std::cout << std::endl;	
	 	ok=true;
	}
	else {
		cout << endl << "You can`t make this action";
		m=false;
	}
	return ok;	
}

int main () {
    float **matrix, **matrix1, **matrix2;
    unsigned int rows1, rows2, rows3, columns1, columns2, columns3;
    char op;
    bool ok=false;
	cin >> rows1;
	op=cin.get();
	cin >> columns1;
	matrix1= pamyat_dlya_matritzi(matrix1, rows1, columns1);
	matrix1=read_matrix (rows1, columns1, matrix1);
	cin >> op;
	if (op == 'T') {
		rows3=columns1;
		columns3=rows1;
		matrix = pamyat_dlya_matritzi(matrix, rows3, columns3);
	}
	else {
		rows3=rows1;
		columns3=columns1;
		matrix = pamyat_dlya_matritzi(matrix, rows3, columns3);
	}
	switch (op){
		case '+': {
			bool m=true;
			cin >> rows2;
			op=cin.get();
			cin >> columns2;
			matrix2 = pamyat_dlya_matritzi(matrix2, rows2, columns2);
			matrix2=read_matrix (rows2, columns2, matrix2);	
			ok=sum_matrix(matrix1, rows1, columns1, matrix2, rows2, columns2, matrix, rows3, columns3, m);
			delete_pamyat (matrix2, rows2);
			if (!m) {cin.get(); return 0;}
			break;
		}
		case '-': {
			bool m=true;
			cin >> rows2;
			op=cin.get();
			cin >> columns2;
			matrix2 = pamyat_dlya_matritzi(matrix2, rows2, columns2);
			matrix2=read_matrix (rows2, columns2, matrix2);
			ok=sub_matrix(matrix1, rows1, columns1, matrix2, rows2, columns2, matrix, rows3, columns3, m);
			delete_pamyat (matrix2, rows2);
			if (!m) {cin.get(); return 0;}
			break;
		}
		case '*': {
			bool m=true;
			cin >> rows2;
			op=cin.get();
			cin >> columns2;
			matrix2 = pamyat_dlya_matritzi(matrix2, rows2, columns2);
			matrix2=read_matrix (rows2, columns2, matrix2);
			ok=mul_matrix (matrix1, rows1, columns1, matrix2, rows2, columns2, matrix, rows3, columns3, m);
			delete_pamyat (matrix2, rows2);
			if (!m) {cin.get(); return 0;}
	 		break;
		}
		case 'T': {
			for (unsigned int i=0; i<rows1; i++){
				for (unsigned int j=0; j<columns1; j++){
					matrix[j][i]=matrix1[i][j];
				}
			}
			break;
		}
		case 'R': {
			if (columns1==rows1){
				bool m=true;
				ok=gaus_obr(rows1, matrix1, matrix, m);
				if (!m) {cin.get(); return 0;}
			}
			else cout << "An error has occured while reading input data";
			break;
		}
	}
	cout << endl;
	if (op == 'T') {
		write_matrix (matrix, rows3, columns3);
	}
	else {
		if (ok==true){
			write_matrix (matrix, rows3, columns3);
		}
		else {
			cout << "An error has occured while reading input data";
		}
	}
	delete_pamyat (matrix1, rows1);
	delete_pamyat (matrix, rows3);
	cin.get();
	return 0;
}
