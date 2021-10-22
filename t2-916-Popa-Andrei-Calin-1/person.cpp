//
// Created by Andrei on 4/26/2021.
//

#include <iostream>
#include <vector>

class Measurement {
public:
    std::string date;

    std::string toString() {
        return date;
    }

private:
    bool isNormalValue();
};

class BMI : public Measurement
{
public:
    double BMI;
private:
    bool isNormalValue();
    double toString() {
        return BMI;
    }
};

class BP : public Measurement
{
public:
    int systolicValue;
    int diastolicValue;
private:
    bool isNormalValue();
    std::string toString() {
        std::string str= systolicValue + "  " + diastolicValue;
        return str;
    }
};

class Person
{
private:
    std::vector<Measurement> mList;
public:
    std::string name;

    void addMeasurement(Measurement a) {
        mList.push_back(a);
    }
    void getAllMeasurements();
    void getMeasurementsByMonth(int month);
    bool isHealthy();
    void getMeasurementsNewerThan(std::string date);
    void wireToFile(std::string filename, std::string date);

    std::vector<Measurement> getAll() {
        return mList;
    }
    std::string toString() {
        std::string str;
        for (auto &m : mList) {
            str += m.toString() + '\n';
        }
        return str;
    }
};

class Service {
public:
    Measurement createBMIMeasurement(std::string date, double BMI) {
        class BMI m;
        m.BMI = BMI;
        m.date = date;
        return m;
    }

    std::string display() {

    }
};