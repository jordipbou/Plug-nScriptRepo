#include "library/Midi.hxx"

// metadata
string name="MIDI Thru Test";
string description="MIDI Thru Test";

// parameters
array<string> inputParametersNames={"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"};
array<double> inputParameters(inputParametersNames.length);

array<double> inputParametersMin={0,1,0};
array<double> inputParametersMax={16,16,1};
array<double> inputParametersDefault={0,1,0};
array<int>    inputParametersSteps={17,16,2};
array<string> inputParametersFormats={".0", ".0", "0."} ;

void initialize ()
{
}

void processBlock(BlockData& data)
{
    for(uint i=0;i<data.inputMidiEvents.length;i++)
    {
        // forward event (unchanged)
        data.outputMidiEvents.push(data.inputMidiEvents[i]);
    }
}
