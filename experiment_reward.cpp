#include <iostream>
#include <vector>
#include <string>

#include "MultiNightBar.hpp"

int main(){

    std::cout << "MultiNightBar Reward Experiment" << std::endl;

    int nAgents = 100;
    int nNights = 10;
    int cap = 10;
    int runFlag = 8;
    // int tau = 200;
    bool learnTypeD = true;
    bool impactTypeD = false;
    double learningRate = 0.1;
    double exploration = 0.01;
    std::string base_path = "Results/reward_D/";


    std::vector<double> taus = {1.0, 2.0, 3.0};
    int numRuns = 2;
    int numEpochs = 3000;
    std::vector<int> gracePeriods = {0, 10, 50, 100};

    for (size_t g = 0; g < gracePeriods.size(); ++g){

        for (size_t i = 0; i < taus.size(); ++i){

            for (int j = 0; j < numRuns; ++j){

                std::string path = base_path + "tau_" + std::to_string(taus[i]) + "/grace_" + std::to_string(gracePeriods[g]) + "/run_" + std::to_string(j) + "/";

                MultiNightBar barProblem(nAgents, nNights, cap, runFlag, taus[i], 
                                learnTypeD, impactTypeD, 
                                learningRate, exploration,
                                path, gracePeriods[g]);

                for (int k = 0; k < numEpochs; ++k){
                    barProblem.simulateEpoch(k);
                }

                barProblem.logQTables();
            }

        }
    }

}