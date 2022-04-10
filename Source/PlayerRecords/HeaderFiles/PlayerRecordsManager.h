#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <PlayerRecords/HeaderFiles/PlayerRecord.h>


class PlayerRecordsManager
{
public:
    PlayerRecordsManager();
    std::list<PlayerRecord> GetAllPlayerRecords();
    void AddRecordToListIfEnoughPoints(PlayerRecord record);
private:
	std::list<PlayerRecord> listOfRecords;
    void LoadListFromFile();
    void WriteListToFile();
    void SortRecordsInList();
};