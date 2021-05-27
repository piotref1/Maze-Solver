#include <iostream>
	
	void returning(int tab[], int current_pos, int choices[], sf::RenderWindow &window);
	int crossroads(int tab[], int current_pos, int choices[]);
	
	void movement(int tab[],int current_pos, sf::RenderWindow &window)
	{ /*
		1. Check around for crossroad. 
		2. Check at the same time where road is located and if exit exists. ( void crossroads )
		3. If exit exists, end.
		4. If not. Move in the direction that's available. Right>Left>Up>Down
		5. Mark it as treaded path.
		6. Repeat 1
	  */
		//std::queue <int> crossroads;
		int solved = 0;
		int choices[4] = { 0,0,0,0 };
		
		solved = crossroads(tab, current_pos,choices);
		if(solved!=1) //solve loop
		{
			tab[current_pos] = 4; //poison
			drawing_during(tab, window);
			//Movement//
			if(choices[0]==3)
			{
				current_pos = current_pos + 1; //right
				movement(tab, current_pos,window);
			}
			else if (choices[1]==3)
			{
				
				current_pos = current_pos - 1; //left
				movement(tab, current_pos,  window);
			}
			else if (choices[2]==3)
			{				
				current_pos = current_pos+22; //down
				movement(tab, current_pos,  window);
			}
			else if (choices[3]==3)
			{
				current_pos = current_pos-22; //up
				movement(tab, current_pos, window);
			}
			else
			{
				//return part
				tab[current_pos] = 5;
				if (choices[1] == 4)
				{
					current_pos = current_pos - 1; //left
					std::cout << "Right b" << std::endl;
					movement(tab, current_pos,  window);
				}
				
				else if (choices[0] == 4)
				{
					current_pos = current_pos + 1; //right
					std::cout << "Left b" << std::endl;
					movement(tab, current_pos, window);
				}
				else if (choices[3] == 4)
				{
					current_pos = current_pos - 22; //up
					std::cout << "Down b" << std::endl;
					movement(tab, current_pos, window);
				}else if (choices[2] == 4)
				{
					current_pos = current_pos + 22; //down
					std::cout << "Up b" << std::endl;
					movement(tab, current_pos,  window);
				}
				else
				{
					std::cout << "couldn't find exit" << std::endl;
				}
			}
		
		}
		else { std::cout << "Maze solved" << std::endl; }
	}

	int crossroads(int tab[], int current_pos, int choices[])
	{
		int cross=0;
		int exit_found = 0;
		int temp=0;
		choices[0] = tab[current_pos + 1]; //right
		choices[1] = tab[current_pos - 1]; //left
		choices[2] = tab[current_pos + 22]; //down
		choices[3] = tab[current_pos - 22]; //up
		for(int i=0;i<4;i++)
		{
			
			if (choices[i] == 2) { exit_found= 1; }
		}

		if (exit_found == 1) 
		{
			return exit_found; std::cout << "Found exit" << std::endl;
		}
		else {
			exit_found = 0; return exit_found; std::cout << "No crossroads" << std::endl;
		}

	};

	void returning(int tab[], int current_pos, int choices[], sf::RenderWindow &window)
	{
		int solved = 0;
		
		tab[current_pos] = 0;
		solved = crossroads(tab, current_pos, choices);
		if (solved != 1) //solve loop
		{

			if(choices[0]==3 || choices[1]==3 || choices[2]==3 || choices[3]==3)
			{
				movement(tab, current_pos,  window);
			}
			else if (choices[2] == 3)
			{
				tab[current_pos] = 0;
				current_pos = current_pos + 22; //down
				std::cout << "Down b" << std::endl;
				returning(tab, current_pos, choices, window);
			}
			else if (choices[0] == 4)
			{
				tab[current_pos] = 0;
				current_pos = current_pos + 1; //right
				std::cout << "Right b" << std::endl;
				returning(tab, current_pos, choices, window);
			}
			else if (choices[3] == 4)
			{
				tab[current_pos] = 0;
				current_pos = current_pos - 22; //up
				std::cout << "Up b" << std::endl;
				returning(tab, current_pos, choices, window);

			}
			else if (choices[1] == 3)
			{
				tab[current_pos] = 0;
				current_pos = current_pos -1; //down
				std::cout << "Down b" << std::endl;
				returning(tab, current_pos, choices, window);
			}
			
			
		}




	};

