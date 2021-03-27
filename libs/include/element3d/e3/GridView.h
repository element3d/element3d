#ifndef __CARBON_GRIDVIEW__
#define __CARBON_GRIDVIEW__

#include "LinearLayout.h"
#include "Template.h"
#include <vector>
#include <functional>

namespace e3
{
    typedef std::function<void(int, e3::Template*)> OnRecyclerViewItemLoadCallback;
    typedef std::function<void(int, e3::Template*)> OnRecyclerViewItemUnloadCallback;

    template <class A>
    class GridView : public e3::LinearLayout
    {
    public:
        GridView() : LinearLayout()
        {
            setOrientation(EOrientation::Vertical);
            mType = EViewType::RecyclerView;
            YGNodeStyleSetOverflow(mNode, YGOverflowScroll);
            SetAlignItemsVer(e3::EAlignment::Start);
            SetAlignItemsHor(e3::EAlignment::Start);
        }

        virtual void update() override
        {
            LinearLayout::update();
            mVisibleRect = mRect;
            if (orientation() == EOrientation::Vertical)
                mVisibleRect.height *= 1.5;
            else
                mVisibleRect.width *= 1.5;

            DoScroll();
        }

        void Insert(int offset, int count)
        {
            mLoadMap = new bool[count];
            memset(mLoadMap, 0, count);
            mNumItems = count;
            mNumRows = int((float)count / (float)mNumColumns) + 1;
            for (int i = 0; i < mNumRows; ++i)
            {
                LinearLayout* pLayout = new LinearLayout();
                pLayout->setWidth(1.0f/* / mNumColumns*/);
                pLayout->SetAlignItemsVer(e3::EAlignment::Start);
                pLayout->SetAlignItemsHor(e3::EAlignment::Start);
//                pLayout->setHeight(1);
                addView(pLayout);
            }
            for (int i = 0; i < count; ++i)
            {
                A* pAdapter = new A();

//                if (orientation() == EOrientation::Vertical)
//                {
//                    pAdapter->setHeight(mItemHeight);
//                    pAdapter->setWidth(1);
//                }
//                else
//                {
//                    pAdapter->setHeight(1);
//                    pAdapter->setWidth(mItemWidth);
//                }
                int index = i / mNumColumns;
                pAdapter->SetVisibility(EVisibility::Hidden);
                pAdapter->setWidth(1.0f / mNumColumns);
                if (mItemHeight) pAdapter->setHeight(mItemHeight);
                LinearLayout* pLayout = static_cast<LinearLayout*>(Children()[index]);
                pLayout->addView(pAdapter);

            }
        }
        void draw() override
        {
            glEnable(GL_SCISSOR_TEST);
            //glViewport(mRect.x, mRect.y, mRect.width, mRect.height);
            glScissor(mRect.x, sScreenHeight - mRect.y - mRect.height, mRect.width, mRect.height);

            LinearLayout::draw();
            glDisable(GL_SCISSOR_TEST);
        }

        void SetItemHeight(float itemHeight)
        {
            mItemHeight = itemHeight;
            mNumVisibleItems = (int)mRect.height / mItemHeight + 4;
            if (!mLastVisibleItemIndex) mLastVisibleItemIndex = mNumVisibleItems - 1;
        }

        void SetItemWidth(float itemWidth)
        {
            mItemWidth = itemWidth;
            mNumVisibleItems = (int)mRect.width / mItemWidth + 4;
            if (!mLastVisibleItemIndex) mLastVisibleItemIndex = mNumVisibleItems - 1;
        }

        void SetNumColumns(int numColumns)
        {
            mNumColumns = numColumns;
        }

        void DoScroll()
        {
            for (int i = 0; i < NumChildren(); ++i)
            {
                LinearLayout* pAdapter = static_cast<LinearLayout*>(Children()[i]);
                if (mVisibleRect.contains(pAdapter->rect().tl()) && pAdapter->Visibility() == EVisibility::Hidden)
                {
                    pAdapter->SetVisibility(EVisibility::Visible);
                    for (int j = 0; j < pAdapter->NumChildren(); ++j)
                    {
                        int index = mNumColumns * i + j;
                        if (!mLoadMap[index] && index < mNumItems)
                        {
                            mOnRecyclerViewItemLoadCallback(index,static_cast<e3::Template *>(pAdapter->Children()[j]));
                            mLoadMap[index] = true;
                        }
                    }
                }
                else if (!mVisibleRect.contains(pAdapter->rect().tl()) && pAdapter->Visibility() == EVisibility::Visible)
                {
                    for (int j = 0; j < pAdapter->NumChildren(); ++j)
                    {
                        int index = mNumColumns * i + j;
                        if (index < mNumItems)
                            mOnRecyclerViewItemUnloadCallback(index, static_cast<e3::Template*>(pAdapter->Children()[j]));
                    }
                    pAdapter->SetVisibility(EVisibility::Hidden);
                }
            }
        }

        virtual void OnScroll(const glm::vec2& distance) override
        {
            if (orientation() == EOrientation::Vertical)
                mVisibleRect.y = mRect.y - mChildrenScrollDirection.y;
            else
                mVisibleRect.y = mRect.x - mChildrenScrollDirection.x;

            DoScroll();
//            if (orientation() == EOrientation::Vertical)
//                mVisibleRect.y = mRect.y - mChildrenScrollDirection.y;
//            else
//                mVisibleRect.y = mRect.x - mChildrenScrollDirection.x;
//
//            for (int i = 0; i < NumChildren(); ++i)
//            {
//                LinearLayout* pAdapter = static_cast<LinearLayout*>(Children()[i]);
//                if (mVisibleRect.contains(pAdapter->rect().tl()) && pAdapter->Visibility() == EVisibility::Hidden)
//                {
//                    pAdapter->SetVisibility(EVisibility::Visible);
//                    for (int j = 0; j < pAdapter->NumChildren(); ++j)
//                    {
//                        int index = mNumRows * i + j;
//                        if (index < mNumItems)
//                            mOnRecyclerViewItemLoadCallback(index, static_cast<Template*>(pAdapter->Children()[j]));
//                    }
//                }
//                else if (!mVisibleRect.contains(pAdapter->rect().tl()) && pAdapter->Visibility() == EVisibility::Visible)
//                {
//                    for (int j = 0; j < pAdapter->NumChildren(); ++j)
//                    {
//                        int index = mNumRows * i + j;
//                        if (index < mNumItems)
//                            mOnRecyclerViewItemUnloadCallback(index, static_cast<Template*>(pAdapter->Children()[j]));
//                    }
//                    pAdapter->SetVisibility(EVisibility::Hidden);
//                }
//            }

//            for (int i = 0; i < NumChildren(); ++i)
//            {
//                Template* pView = static_cast<Template*>(Children()[i]);
//                if (!mVisibleRect.contains(pView->rect().tl()) && pView->Visibility() == EVisibility::Visible)
//                {
//                    mOnRecyclerViewItemUnloadCallback(i, pView);
//                    ALOGE("UNLOAD %i\n", i);
//                    pView->SetVisibility(EVisibility::Hidden);
//                }
//
//                if (mVisibleRect.contains(pView->rect().tl()) && pView->Visibility() == EVisibility::Hidden)
//                {
//                    mOnRecyclerViewItemLoadCallback(i, pView);
//                    ALOGE("load %i\n", i);
//                    pView->SetVisibility(EVisibility::Visible);
//                }
//            }
        }

        void SetOnRecyclerViewItemLoadCallback(OnRecyclerViewItemLoadCallback callback)
        {
            mOnRecyclerViewItemLoadCallback = callback;
        }

        void SetOnRecyclerViewItemUnloadCallback(OnRecyclerViewItemUnloadCallback callback)
        {
            mOnRecyclerViewItemUnloadCallback = callback;
        }

    public:
        void AddItem(e3::Template* pItem)
        {
            //pItem->setGravityVer(EGravity::Start);
            //addView(pItem);
        }

        //std::vector<A*> mItems;
        float mItemHeight = 1;
        float mItemWidth = 1;
        int mNumColumns = 0;
        int mNumRows = 0;
        int mNumItems = 0;
        bool* mLoadMap = nullptr;

        int mNumVisibleItems = 0;
        int mFirstVisibleItemIndex = 0;
        int mLastVisibleItemIndex = 0;
        e3::Rect2f mVisibleRect;

        OnRecyclerViewItemLoadCallback mOnRecyclerViewItemLoadCallback = nullptr;
        OnRecyclerViewItemUnloadCallback mOnRecyclerViewItemUnloadCallback = nullptr;

    };
}

#endif // __CARBON_GRIDVIEW__