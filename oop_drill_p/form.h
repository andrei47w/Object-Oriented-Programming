#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "read_file.h"
#include <QPainter>
#include <iostream>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        auto maxDiameter = std::min(this->width(), this->height());
        painter.translate(this->width() / 2.0, this->height() / 2.0);

        for (auto const &element: this->p_repo.get_elem()) {
            auto diameter = std::stoi(element[1]) * maxDiameter / std::stoi(element[2]);
            painter.setPen(std::stoi(element[1]) > std::stoi(element[2]) ? Qt::blue : Qt::red);
            painter.drawEllipse(-diameter / 2, -diameter / 2, diameter, diameter);
            painter.drawText(-diameter / 2, 0, element[0].c_str());
        }
    }

private:
    Ui::Form *ui;
    Repository p_repo = Repository("programmers.txt");
};

#endif // FORM_H
