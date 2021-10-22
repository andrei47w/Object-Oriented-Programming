#include "TableModel.h"
#include <qmessagebox.h>

TableModel::TableModel() : QAbstractTableModel() {

}

TableModel::TableModel(Repository* repo) {
    this->repo = repo;
}

TableModel::~TableModel() {
    delete repo;
}

int TableModel::rowCount(const QModelIndex &parent) const {
    return repo->get_elem().size();
}

int TableModel::columnCount(const QModelIndex &) const {
    return 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();
    //if (index.column() == 1) {
    auto v = repo->get_elem();

    auto tut = (v)[index.row()];
    //}
    switch (index.column()) {
        case 0: {
            return tr(tut[0].c_str());
        }
        case 1:
            return tr(tut[1].c_str());
        case 2:
            return tr(tut[2].c_str());
        default:
            return QVariant();
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    {
        if (role != Qt::DisplayRole)
            return QVariant();

        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return tr("Name");

                case 1:
                    return tr("yes");
                case 2:
                    return tr("yes2");
                default:
                    return QVariant();
            }
        }
        return QVariant();
    }
}

bool TableModel::addTableToRepository(std::string name, std::string revised, std::string total) {
        beginInsertRows(QModelIndex(), 0, 0);

    std::vector<std::string> p;
    p.push_back(name);
    p.push_back(revised);
    p.push_back(total);
    repo->get_elem().push_back(p);

        endInsertRows();
        return true;
}

//
//bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
//    if (!index.isValid() || role != Qt::EditRole)
//        return false;
//    int row = index.row();
//
//        switch (index.column()) {
//            case 0: {
//                std::string presenter = index.data().toString().toStdString();
//                //repo->updateTable(Table{ p.getTitle(),value.toString().toStdString(),Duration{ p.getDuration().getMinutes(),p.getDuration().getSeconds() },p.getNoLikes(),p.getSource(),p.getNoViews() }, presenter, p.getTitle());
//                repo->updateTable(TableFactory::MakeTable(p.getTitle(), value.toString().toStdString(),
//                                                                   std::to_string(p.getDuration().getMinutes()),
//                                                                   std::to_string(p.getDuration().getSeconds()),
//                                                                   std::to_string(p.getNoLikes()), p.getSource(),
//                                                                   std::to_string(p.getNoViews())), presenter,
//                                     p.getTitle());
//                Table newT = Table{p.getTitle(), value.toString().toStdString(),
//                                         Duration{p.getDuration().getMinutes(), p.getDuration().getSeconds()},
//                                         p.getNoLikes(), p.getSource(), p.getNoViews()};
//            }
//                break;
//            case 1: {
//                std::string title = index.data().toString().toStdString();
//                repo->updateTable(TableFactory::MakeTable(value.toString().toStdString(), p.getPresenter(),
//                                                                   std::to_string(p.getDuration().getMinutes()),
//                                                                   std::to_string(p.getDuration().getSeconds()),
//                                                                   std::to_string(p.getNoLikes()), p.getSource(),
//                                                                   std::to_string(p.getNoViews())), p.getPresenter(),
//                                     title);
//                Table newT = TableFactory::MakeTable(value.toString().toStdString(), p.getPresenter(),
//                                                              std::to_string(p.getDuration().getMinutes()),
//                                                              std::to_string(p.getDuration().getSeconds()),
//                                                              std::to_string(p.getNoLikes()), p.getSource(),
//                                                              std::to_string(p.getNoViews()));
//                std::unique_ptr<Action> action{new UpdateAction(repo, p, newT)};
//                undoActions.push_back(std::move(action));
//                redoActions.clear();
//            };
//
//                break;
//            case 2: {
//                std::string noLikes = value.toString().toStdString();
//                repo->updateTable(TableFactory::MakeTable(p.getTitle(), p.getPresenter(),
//                                                                   std::to_string(p.getDuration().getMinutes()),
//                                                                   std::to_string(p.getDuration().getSeconds()),
//                                                                   noLikes, p.getSource(),
//                                                                   std::to_string(p.getNoViews())), p.getPresenter(),
//                                     p.getTitle());
//                Table newT = TableFactory::MakeTable(p.getTitle(), p.getPresenter(),
//                                                              std::to_string(p.getDuration().getMinutes()),
//                                                              std::to_string(p.getDuration().getSeconds()), noLikes,
//                                                              p.getSource(), std::to_string(p.getNoViews()));
//                std::unique_ptr<Action> action{new UpdateAction(repo, p, newT)};
//                undoActions.push_back(std::move(action));
//                redoActions.clear();
//            };
//        };
//
//    emit dataChanged(index, index);
//    return true;
//}

bool TableModel::addTableToRepository(std::string name, std::string status, std::string creator, std::string reviewer) {
    beginInsertRows(QModelIndex(), 0, 0);

    std::vector<std::string> f;
    f.push_back(name);
    f.push_back(status);
    f.push_back(creator);
    f.push_back(reviewer);
    repo->get_elem().push_back(f);

    endInsertRows();
    return true;
}

