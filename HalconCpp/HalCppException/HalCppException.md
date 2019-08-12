# 

##

###

```
	try
	{
		//Halcon procedures
        //ResultAnalog = Analog(InstrumentPath, ImageAnalogPath);
		//std::cout << ResultAnalog << "\n";
	}
	catch (HException &except) {
		//Print to console
        std::cout << string(except.ErrorMessage()) << "\n";
	}

```