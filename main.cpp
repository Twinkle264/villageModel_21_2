#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum RoomType {
    CHILDRENS = 1,
    KITCHEN = 2,
    BATHROOM = 3,
    BEDROOM = 4,
    GUESTROOM = 5
};

enum BuildType {
    HOUSE = 1,
    BATH = 2,
    GARAGE = 3,
    BARN = 4
};

struct SPlot {

    struct SBuilding {

        struct SBath {
            double area = 0;
            bool chimney = false;
        } bath;

        struct SHouse {
            struct SFloor {
                struct SRoom {

                    RoomType type;
                    double area = 0;
                } room;

                vector<SRoom> rooms;
                double ceiling_height = 0;
            } floor;

            vector<SFloor> floors;
            double area = 0;
            bool chimney = false;
        } house;

        double area = 0;
        BuildType type;
    } building;

    vector<SBuilding> buildings;
    double area = 0;
} plot;

int main() {
    vector<SPlot> plots;
    cout << "Enter the number of plots in the village:";
    int count_plot = 0;
    cin >> count_plot;

    for (int i = 1; i <= count_plot; ++i) {
    cout << endl;
        cout << "Fill " << i << " plot." << endl;
        cout << "Enter the area of plot:";
        cin >> plot.area;

        cout << "Enter the number of buildings in the plot:";
        int count_buildings = 0;
        cin >> count_buildings;

        for (int j = 1; j <= count_buildings; ++j) {
        cout << endl;
            cout << "Fill " << j << " build." << endl;
            cout << "Enter the type of build: ";
            cout << HOUSE << "-House, " << BATH << "-Bathhouse, " << GARAGE << "-Garage, " << BARN << "-Barn" << endl;
            int type = 0;
            cin >> type;
            plot.building.type = static_cast<BuildType>(type);

            if (plot.building.type == GARAGE || plot.building.type == BARN) {
                cout << endl;
                cout << "Enter the area of build: ";
                cin >> plot.building.area;
            } else if (plot.building.type == BATH) {
                cout << endl;
                cout << "Enter the area of bathhouse: ";
                cin >> plot.building.bath.area;
                cout << endl;
                cout << "Is there a chimney oven in the building? (y/n)" << endl;
                char chimney;
                cin >> chimney;
                if (chimney == 'y') {
                    plot.building.bath.chimney = true;
                } else if (chimney == 'n') {
                    plot.building.bath.chimney = false;
                }
            } else if (plot.building.type == HOUSE) {
                cout << endl;
                cout << "Enter the area of house: ";
                cin >> plot.building.house.area;
                cout << endl;

                cout << "Is there a chimney oven in the house? (y/n)" << endl;
                char chimney;
                cin >> chimney;
                if (chimney == 'y') {
                    plot.building.house.chimney = true;
                } else if (chimney == 'n') {
                    plot.building.house.chimney = false;
                }

                cout << "How many floors in the house?";
                int floors_house = 0;
                cin >> floors_house;

                for (int k = 1; k <= floors_house; ++k) {
                    cout << endl;
                    cout << "Fill " << k << " floor." << endl;
                    cout << "What is the height of the ceilings on the " << k << " floor:";
                    cin >> plot.building.house.floor.ceiling_height;

                    cout << endl << "Enter number of rooms per floor:";
                    int rooms_floor = 0;
                    cin >> rooms_floor;

                    for (int l = 1; l <= rooms_floor; ++l) {
                        cout << endl;
                        cout << "Fill " << l << " room on the " << k << " floor." << endl;

                        cout << "Enter the type of room: ";
                        cout << CHILDRENS << "-Children's room, " << KITCHEN << "-Kitchen, " << BATHROOM << "-Bathroom, "
                            << BEDROOM << "-Bedroom, " << GUESTROOM << "-Guestroom" << endl;
                        int type_room = 0;
                        cin >> type_room;
                        plot.building.house.floor.room.type = static_cast<RoomType>(type_room);

                        cout << "Enter the area of room:";
                        cin >> plot.building.house.floor.room.area;

                        plot.building.house.floor.rooms.push_back(plot.building.house.floor.room);
                    }
                    plot.building.house.floors.push_back(plot.building.house.floor);
                }
                plot.buildings.push_back(plot.building);
            }
        }
        plots.push_back(plot);
    }
    return 0;
}
