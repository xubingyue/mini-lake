/**
* 
* @file     mini-lake
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/11/22
*/
#include <iostream>
#include <stdexcept>
#include <lake/mini-lake-application.hpp>

int main(int args, char ** argv)
{
	try
	{
		return lake::application(args,argv).run();
	}
	catch(const std::exception & e)
	{
		std::cerr << "exception !!!!!!! " << std::endl << "\t" << e.what() << std::endl;

		return 1;
	}
	
}