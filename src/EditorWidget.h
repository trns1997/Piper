#ifndef PIPER_EDITOR_WIDGET_H
#define PIPER_EDITOR_WIDGET_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui
{
    class EditorWidget;
}

namespace piper
{
    class Scene;
    class ExportBackend;

    class EditorWidget : public QWidget
    {
        Q_OBJECT

        friend QDataStream& operator<<(QDataStream& out, EditorWidget const& editor);
        friend QDataStream& operator>>(QDataStream& in,  EditorWidget& editor);

    public:
        EditorWidget(QWidget* parent = nullptr);
        virtual ~EditorWidget() = default;

        void onExport(ExportBackend& backend);
        void loadJson(QJsonObject& json);

    public slots:
        void onAddStage();
        void onRmStage();
        void onColorStage();

        void onAddMode();
        void onRmMode();

    private:
        Ui::EditorWidget* ui_;
        Scene* scene_;
    };

    QDataStream& operator<<(QDataStream& out, EditorWidget const& editor);
    QDataStream& operator>>(QDataStream& in,  EditorWidget& editor);
}

#endif
