#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

// Define la Clase Channel
class Channel {
private:
    double voltage; // voltage del canal
    int resolution; // resolucion del canal

public:
    // constructor Default 
    Channel() {}

    // funcion Setter para el voltage
    void setVoltage(double v) {
        if (v > 3.3) {
            voltage = 3.3;
        } else if (v < 0) {
            voltage = 0;
        } else {
            voltage = v;
        }
    }

    // funcion Setter para resolucion
    void setResolution(int r) {
        if (r == 8 || r == 10 || r == 12) {
            resolution = r;
        } else {
            resolution = 10; 
        }
    }

    // funcion para obtener voltage
    double getVoltage() {
        return voltage;
    }

    // funcion para obtener resolucion
    int getResolution() {
        return resolution;
    }

    // calcula y devuelve el valor convertido en ADC
    int getADC() {
        int adc = static_cast<int>(round(voltage / 3.3 * (pow(2, resolution) - 1)));
        return adc;
    }
};

int main() {
    int numChannels;
    cout << "Enter the number of channels: ";
    cin >> numChannels;

    vector<Channel> channels(numChannels); 

    // Hace un Loop para cada canal y pide el voltage y reolucion
    for (int i = 0; i < numChannels; i++) {
        cout << "Enter voltage and resolution (separated by comma) for channel AN" << i+1 << ": ";
        string input;
        cin >> input;

        // Usa stringstream para agarrar la linea en la que se define el voltage y resolucion
        stringstream ss(input);
        string line;

        getline(ss, line, ',');
        double voltage = stod(line);

        getline(ss, line, ',');
        int resolution = stoi(line);

        channels[i].setVoltage(voltage);
        channels[i].setResolution(resolution);
    }

    // Imprime el voltage, resolucion y conversion para cada canal
    cout << "Channel\tVoltage\tResolution\tADC Conversion\n";
    for (int i = 0; i < numChannels; i++) {
        cout << "AN" << i+1 << "\t";
        cout <<"      "<< channels[i].getVoltage() << "\t";
        cout <<"      "<< channels[i].getResolution() << "\t\t";
        cout <<"         "<< channels[i].getADC() << "\n";
    }

    return 0;
}

