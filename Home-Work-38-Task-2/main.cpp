#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget mainWindow;

    auto* htmlText = new QTextEdit(&mainWindow);
    htmlText->setReadOnly(false);
    htmlText->setPlainText("<HTML>"
        "<BODY BGCOLOR=GREY>"
        "<H2><CENTER>Gnome Poem 3: Magic Magic</CENTER></H2>"

        "<FONT COLOR=WHITE>"
        "<P ALIGN=\"center\">"
        "<I>"
        "Magic! Magic!<BR>"
        "Are you here?<BR>"
        "Abra-ca-dabra!<BR>"
        "We appear.<BR><BR>"
        "Magic! Magic!<BR>"
        "Gnomes are we.<BR>"
        "Magic gnomes<BR>"
        "Of mystery.<BR>"
        "..."
        "</I>"
        "</P>"
        "</FONT>"
        "</BODY>"
        "</HTML>"
    );

    auto* simpleText = new QTextEdit(&mainWindow);
    simpleText->setHtml(htmlText->toPlainText());

    auto* hBox = new QHBoxLayout(&mainWindow);
    hBox->addWidget(htmlText);
    hBox->addWidget(simpleText);

    QObject::connect(htmlText, &QTextEdit::textChanged, [&htmlText, &simpleText]() {
        simpleText->setHtml(htmlText->toPlainText());
        });

    mainWindow.resize(800, 400);
    mainWindow.show();

    return a.exec();
}
