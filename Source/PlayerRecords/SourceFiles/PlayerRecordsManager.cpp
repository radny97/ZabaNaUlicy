#include "PlayerRecords/HeaderFiles/PlayerRecordsManager.h"

PlayerRecordsManager::PlayerRecordsManager()
{
    LoadListFromFile();
    SortRecordsInList();
}

std::list<PlayerRecord> PlayerRecordsManager::GetAllPlayerRecords()
{
	return this->listOfRecords;
}

void PlayerRecordsManager::AddRecordToListIfEnoughPoints(PlayerRecord record)
{

}

void PlayerRecordsManager::LoadListFromFile()
{
    std::string nazwaPliku = "C:\\¯aba na ulicy\\PlayerRecords\\Records.txt";
    std::ifstream plik;
    plik.open(nazwaPliku.c_str());
    if (!plik.good())
        return;

    while (true)
    {
        std::string name;
        int points;
        plik >> name >> points;

        if (plik.fail())
            break;

        PlayerRecord rec(name, points);
        this->listOfRecords.push_back(rec);
    }
}

void PlayerRecordsManager::WriteListToFile()
{

}

void PlayerRecordsManager::SortRecordsInList()
{
    this->listOfRecords.sort([](PlayerRecord& a, PlayerRecord& b) { return a.GetPoints() > b.GetPoints(); });
}