#include "library/Midi.hxx"

// metadata
string name="MIDI Channel Router";
string description="Conditional routing from 1 to 16 channels";

// parameters
array<double> inputParameters(16);
array<double> inputParametersMin={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
array<double> inputParametersMax={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
array<double> inputParametersDefault={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
array<int>    inputParametersSteps={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
array<string> inputParametersFormats={".0", ".0", ".0", ".0", ".0", ".0", ".0", ".0", ".0", ".0", ".0", ".0", ".0", ".0", ".0", ".0"} ;

MidiEvent tempEvent;

void initialize ()
{
}

void processBlock(BlockData& data)
{
    for (uint i = 0; i < data.inputMidiEvents.length; i++)
    {
        for (uint j = 0; j < inputParameters.length; j++) {
            if (inputParameters[j] > 0) {
                tempEvent = data.inputMidiEvents [i];
                MidiEventUtils::setChannel (tempEvent, j + 1);
                data.outputMidiEvents.push (tempEvent);
            }
        }
    }
}
