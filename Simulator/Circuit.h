#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <set>

using namespace std;

//figure out how to set inputs to gate initially to zerp
struct Signal {
	string name;
	bool value;

	bool operator == (Signal x)
	{
		if (x.name == name && x.value == value)
			return true;
		return false;
	}
};

class Circuit {

	//a component is a "gate"
	struct Component {

		string name;
		string type;
		int delay;
		Signal output;
		vector<Signal> inputs;
	};

	//Do we even need the vector of inputs?
	vector<Signal> Inputs;
	//vector of all the components in the circuit
	vector<Component> Gates;
	//vector that stores log of signals and the index of the gates that it changes
	vector<pair<Signal, int>> Log;
	//keeps track of what signals we have in the circuit
	set <string> signals;

public:
	//takes in the path for the circuit and calls readCircuit on it
	Circuit(string&);
	//destructor
	~Circuit();
	//reads file and populates inputs: uses populateComponent
	//returns -1 if an input to a gate does not exist as a signal in the circuit
	int readCircuit(string);
	//takes string input, parses it then populates and sends back a component, 
	//returns -1 if an input to a gate does not exist as a signal in the circuit
	int populateComponent(string &);
	//returns the log from the components
	vector<pair<Signal, int>>* returnLog();
	//function that receives the index of a gate and a signal and modifies the value of this signal in the input
	void setInput(int , const Signal& signal);
	//function that receives the index of a gate and a signal and modifies the value of the gate Output
	void setOutput(int, const Signal& signal);
	//function that receives the index of a gate and sets its delay
	void setDelay(int, int);
	//function that returns name of a gate based on the index
	const string& getName(int);
	//function that returns type of a gate based on the index
	const string & getType(int);
	//function that returns delay of gate based on the index
	int getDelay(int);
	//function that returns the output of a gate based on the index
	const Signal & getOutput(int);
	//function that returns pointer to the inputs of a gate based on the index
	const vector<Signal> & getInputs(int);
	//function that returns pointer to the inputs of a gate based on the index
	vector<Signal>* getInputsPtr(int);
	//function that returns the number of gates in the circuit
	int getGateNum();
	//returns circuit inputs
	const vector<Signal>& getCircuitInputs();
};

