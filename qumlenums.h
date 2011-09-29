#ifndef QUMLENUMS_H
#define QUMLENUMS_H

typedef enum
{
    ABSTRACT,
    USECASE
} DiagramsEnum;

typedef enum
{
    NONE = 0,
    SELECT,
    ITEM,
    RELATION,

    // Don't use it. (Used to know count of all scene states)
    COUNT
}  SceneState;

#endif // QUMLENUMS_H
