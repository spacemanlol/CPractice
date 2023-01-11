#include "parser.h"

  	Parser::Parser(std::string filename)
	{
           _filename =  filename;
	}

        bool Parser::OpenStream()
	{
		if (_filename.empty())
			return false;
	
		_fs.exceptions(std::ios::failbit);
		try
		{
			_fs.open(_filename.c_str(), std::ios::in);

		}
		catch(std::exception& ex)
		{
                        // Log message
                        std::cout << "Error: " << ex.what() << std::endl;
			return false;
		}

               return true;
		
	}


	std::vector<LLAData> Parser::ParseToLLA()
        {
                std::vector<LLAData> llaStore;
		if (!OpenStream())
			return llaStore;

                std::string field;
                std::cout << std::fixed << std::setprecision(PRECISION);
                int i = 0;
                while (_fs.peek() != EOF && getline(_fs, field, ','))
                {
                   if (field.empty() || stold(field) < 0.000000001)
			continue;

                   LLAData data;
                   data.time_epoch = stold(field);
		   getline(_fs, field, ',');
                   data.latitude = stold(field);
                    
		   getline(_fs, field, ',');
		   data.longitude = stold(field);

		   getline(_fs, field);
                   // given data in in KM but the equation required in meters
                   data.altitude = 1000.0 * stold(field);

                   llaStore.push_back(data);
                   i++;

		   std::cout << "LLA " << i << ": ";
                   data.Print();
	        };
                std::cout << "Total data: " << i << std::endl;

                CloseStream();
                
               	return llaStore;
        }

        void Parser::CloseStream()
        {

            if (_fs.is_open())
               _fs.close();
        }

       Parser::~Parser()
       {
          CloseStream();
       }
