#ifndef __CARBON_RecyclerView_VIEW__
#define __CARBON_RecyclerView_VIEW__

#include "ScrollView.h"
#include "Template.h"
#include <vector>
#include <functional>

namespace e3
{
    typedef std::function<void(int, e3::Template*)> OnRecyclerViewItemLoadCallback;
    typedef std::function<void(int, e3::Template*)> OnRecyclerViewItemUnloadCallback;
    typedef std::function<void(int, e3::Template*)> OnRecyclerViewItemClickCallback;

    template <class A>
    class RecyclerView : public ScrollView
    {
    public:
        RecyclerView() : ScrollView()
        {
            SetOrientation(EOrientation::Vertical);
            mType = EViewType::RecyclerView;
            // YGNodeStyleSetOverflow(mNode, YGOverflowScroll);
            SetAlignItemsVer(e3::EAlignment::Start);
            SetAlignItemsHor(e3::EAlignment::Start);
        }

        ~RecyclerView()
        {
            mItems.clear();
            delete[] mLoadMap;
        }

        virtual void Update() override
        {
            ScrollView::Update();
            mVisibleRect = mRect;

            if (GetOrientation() == EOrientation::Vertical)
            {
                mVisibleRect.y = mRect.y + mChildrenScrollDirection.y;
                mVisibleRect.height *= 1.5;
            }
            else
            {
                mVisibleRect.x = mRect.x - mChildrenScrollDirection.x;
                mVisibleRect.width *= 1.5;
            }

            DoScrollLoad();
        }

        void Insert(int offset, int count)
        {
			if (!mLoadMap)
			{
				mLoadMap = new bool[count];
				memset(mLoadMap, 0, count);
			}
			else 
			{
				int c = mItems.size() + count;
				bool* pLoadMap = new bool[c];
				memset(pLoadMap, 0, c);
				memcpy(pLoadMap, mLoadMap, offset);
				memcpy(pLoadMap + offset + count, mLoadMap + offset, mItems.size() - offset);
				delete[] mLoadMap;
				mLoadMap = pLoadMap;
			}

            for (int i = 0; i < count; ++i)
            {
                A* pAdapter = new A();
                pAdapter->SetOnClickCallback([this, i, pAdapter](const glm::vec2& pos){
                    if (!mOnItemClickCallback) return;

                    mOnItemClickCallback(i, pAdapter);
                });

                mItems.insert(mItems.begin() + offset + i, pAdapter);
                InsertElement(offset + i, pAdapter);
                pAdapter->SetVisibilityInternal(EVisibility::Hidden);

            }
        }
//        void draw(/*const glm::mat4& projection*/) override
//        {
//            /*mScrolledRect = mRect;
//            glm::vec4 scrolledPos = mSelfScrollTranform * glm::vec4(position(), 0.0, 1.0);
//            mScrolledRect.x = scrolledPos.x;
//            mScrolledRect.y = scrolledPos.y;*/
//            bool scissorEnables = glIsEnabled(GL_SCISSOR_TEST);
//            float scissor[4];
//            glEnable(GL_SCISSOR_TEST);
//            e3::Rect2f scissorRect(mScrolledRect.x,
//                                 sScreenHeight - mScrolledRect.y - mScrolledRect.height,
//                                 mScrolledRect.width, mScrolledRect.height);
//            if (scissorEnables)
//            {
//                glGetFloatv(GL_SCISSOR_BOX, scissor);
//                e3::Rect2f oldScissorRect(scissor[0], scissor[1], scissor[2], scissor[3]);
//
//                scissorRect = scissorRect & oldScissorRect;
//            }
//            glScissor(scissorRect.x, scissorRect.y, scissorRect.width, scissorRect.height);
//
//            ScrollView::draw();
//
//            if (!scissorEnables)
//            {
//                glDisable(GL_SCISSOR_TEST);
//            }
//            else
//            {
//
//                glScissor(scissor[0], scissor[1], scissor[2], scissor[3]);
//            }
//        }

        void SetItemHeight(float itemHeight)
        {
            /*mItemHeight = itemHeight;
            mNumVisibleItems = (int)mRect.height / mItemHeight + 4;
            if (!mLastVisibleItemIndex) mLastVisibleItemIndex = mNumVisibleItems - 1;*/
        }

        void SetItemWidth(float itemWidth)
        {
         /*   mItemWidth = itemWidth;
            mNumVisibleItems = (int)mRect.width / mItemWidth + 4;
            if (!mLastVisibleItemIndex) mLastVisibleItemIndex = mNumVisibleItems - 1;*/
        }

        virtual void OnScroll(const glm::vec2& distance) /*override*/
        {
            if (GetOrientation() == EOrientation::Vertical)
                mVisibleRect.y = mRect.y - mChildrenScrollDirection.y;
            else
                mVisibleRect.x = mRect.x - mChildrenScrollDirection.x;

           DoScrollLoad();
        }

        void DoScrollLoad()
        {
            for (int i = 0; i < mItems.size(); ++i)
            {
                e3::Template* pView = static_cast<e3::Template*>(mItems[i]);

                e3::Rect2f vr(pView->GetRect().x + 1, pView->GetRect().y + 1, pView->GetRect().width - 2, pView->GetRect().height - 2);
                if (!mVisibleRect.contains(vr.tl()) && !mVisibleRect.contains(vr.br()) /*&& pView->Visibility() == EVisibility::Visible*/)
                {
                    bool a= mVisibleRect.contains(vr.tl());
                    bool b = mVisibleRect.contains(vr.br());
                    if (i == 15 || i == 16)
                    {
                        printf("");
                    }
                    if (mOnRecyclerViewItemUnloadCallback)
                        mOnRecyclerViewItemUnloadCallback(i, pView);
                    pView->SetVisibilityInternal(EVisibility::Hidden);
                }

                if (mVisibleRect.contains(vr.tl()) || mVisibleRect.contains(vr.br()) /*&& pView->Visibility() == EVisibility::Hidden*/)
                {
					if (!mLoadMap[i])
					{
						if (mOnRecyclerViewItemLoadCallback)
						{
							mLoadMap[i] = true;
							mOnRecyclerViewItemLoadCallback(i, pView);
						}
                    }
                    pView->SetVisibilityInternal(EVisibility::Visible);
                }
            }
        }

        void SetOnRecyclerViewItemLoadCallback(OnRecyclerViewItemLoadCallback callback)
        {
            mOnRecyclerViewItemLoadCallback = callback;
        }

        void SetOnRecyclerViewItemUnloadCallback(OnRecyclerViewItemUnloadCallback callback)
        {
            mOnRecyclerViewItemUnloadCallback = callback;
        }

        void SetOnItemClickCallback(OnRecyclerViewItemClickCallback callback)
        {
            mOnItemClickCallback = callback;
        }

    public:
        void AddItem(e3::Template* pItem)
        {
            //pItem->setGravityVer(EGravity::Start);
            AddElement(pItem);
        }

        std::vector<A*> mItems;
       // float mItemHeight = 1.0f;
       // float mItemWidth = 1.0f;
        int mNumVisibleItems = 0;
     //   int mFirstVisibleItemIndex = 0;
   //     int mLastVisibleItemIndex = 0;
        e3::Rect2f mVisibleRect;
        e3::Rect2f mScrollRect;
        bool* mLoadMap = NULL;

        OnRecyclerViewItemLoadCallback mOnRecyclerViewItemLoadCallback = nullptr;
        OnRecyclerViewItemUnloadCallback mOnRecyclerViewItemUnloadCallback = nullptr;
        OnRecyclerViewItemClickCallback mOnItemClickCallback = nullptr;

    };
}

#endif // __CARBON_LIST_VIEW__
