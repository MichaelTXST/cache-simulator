#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct CacheLine {
    bool valid;
    int tag;
};

int main(int argc, char* argv[]) {
    int num_entries = stoi(argv[1]);
    int associativity = stoi(argv[2]);
    string input_file = argv[3];

    int num_sets = num_entries / associativity;

    vector<vector<CacheLine>> cache(num_sets);

    ifstream fin(input_file);
    ofstream fout("cache_sim_output");

    int address;

    while (fin >> address) {
        int set_index = address % num_sets;
        int tag = address / num_sets;

        bool hit = false;
        vector<CacheLine>& current_set = cache[set_index];

        for (int i = 0; i < current_set.size(); i++) {
            if (current_set[i].valid && current_set[i].tag == tag) {
                hit = true;

                CacheLine temp = current_set[i];
                current_set.erase(current_set.begin() + i);
                current_set.push_back(temp);

                break;
            }
        }

        if (hit) {
            fout << address << " : HIT" << endl;
        } else {
            fout << address << " : MISS" << endl;

            CacheLine new_line;
            new_line.valid = true;
            new_line.tag = tag;

            if (current_set.size() < associativity) {
                current_set.push_back(new_line);
            } else {
                current_set.erase(current_set.begin());
                current_set.push_back(new_line);
            }
        }
    }

    fin.close();
    fout.close();

    return 0;
}
