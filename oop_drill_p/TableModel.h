#pragma once
#include <QObject>
#include <QAbstractTableModel>
#include <functional>
#include <vector>
#include <memory>
#include "read_file.h"

class TableModel : public QAbstractTableModel
{
private:
    Repository* repo;
public:
TableModel();
	TableModel(Repository* repo);
	~TableModel();
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &/*parent*/) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;



	// repository
    Repository* getRepo() { return repo; };
	bool addTableToRepository(std::string name, std::string revised, std::string total);
	bool addTableToRepository(std::string name, std::string status, std::string creator, std::string reviewer);
//	bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;

};